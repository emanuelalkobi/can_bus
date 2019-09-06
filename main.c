#include <stdio.h>

#include "data_frame_st.h"
#include "wheel_speeds.h"
#include "brake_module.h"
#include "powertrian.h"
#include "queue.h"

#define  WHEEL_SPEEDS_FREQ 100
#define  BREAK_MODULE_FREQ 10
#define  POWERTRAIN_MODULE_FREQ  25

#define USEC 1000000
#define RESOLUTION 100

int round_resolution(int num,int res){
    int tmp=(num/res)*res+res;
    return tmp;
}

int main() {

    //program parameters

    int drive_session_time_sec  = 600;
    int drive_session_time_usec = 1e6 * drive_session_time_sec;

    int stress_factor=1;

    int wheel_speed_freq  = WHEEL_SPEEDS_FREQ*stress_factor;
    int break_module_freq = BREAK_MODULE_FREQ*stress_factor;
    int power_train_freq  = POWERTRAIN_MODULE_FREQ*stress_factor;

    int wheel_speed_dif  = USEC/wheel_speed_freq;
    int break_module_dif = USEC/break_module_freq;
    int power_train_dif  = USEC/power_train_freq;

    int bit_rate=125*1e3; // default bit rate on  CANopen 125 kbit/s


    int time_to_transfer_wheel= round_resolution(WHEEL_SPEED_BITS_SIZE*USEC/bit_rate,RESOLUTION);
    int time_to_transfer_brake= round_resolution(BREAK_MODULE_BITS_SIZE*USEC/bit_rate,RESOLUTION);
    int time_to_transfer_power= round_resolution(POWERTRAIN_BITS_SIZE*USEC/bit_rate,RESOLUTION);

    int powertrain_msg   = 0;
    int wheel_speeds_msg = 0;
    int break_module_msg = 0;

    FILE *sent_msg;
    FILE *summary_report;

    sent_msg       = fopen("sent_messages.txt", "w+");
    summary_report = fopen("summary_report.txt", "w+");
    fprintf(sent_msg,"---------------------------------------------------------------------------------------------------------------\n");
    fprintf(sent_msg, "sent messages over CAN bus for  %d seconds  stress  factor %d resolution %d usec \n",drive_session_time_sec,stress_factor,RESOLUTION);
    fprintf(sent_msg,"---------------------------------------------------------------------------------------------------------------\n");

    fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");
    fprintf(summary_report, "summary_report over CAN bus for  %d seconds  stress  factor %d resolution %d usec \n",drive_session_time_sec,stress_factor,RESOLUTION);
    fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");

    printf("------\n");
    data_frame* df1;//=create_wheel_speeds(5000,7500,10000,12500);
    data_frame* df2;//=create_break_module(1);
    data_frame* df3;//=create_powertrain(14000);
    //data_frame* df4=create_powertrain(123);
   // data_frame* df5=create_powertrain(1000);

    printf("------\n");

    queue* wheel_speeds_q = new_queue();
    queue* break_module_q = new_queue();
    queue* powertrain_q   = new_queue();


    printf("drive time in sec %d\n",drive_session_time_sec);
    printf("drive time in usec %d\n",drive_session_time_usec);




    int curr_time_usec=0;
    int bus_free = 0;

    //take as step size the smallest between the fastest to transger(brake) and the most frequent(wheel speeds
    // )
    //int step_size=min(time_to_transfer_brake,wheel_speed_freq);

    printf("----------------------------------------------------------\n");
    while(curr_time_usec<drive_session_time_usec){
       // printf("curr time is %d\n",curr_time_usec);
        if(curr_time_usec%wheel_speed_dif==0){
            //printf("create new wheel_speed message and insert to queue %d \n",curr_time_usec);
            df1=create_wheel_speeds(5000,7500,10000,12500);
            enqueue(wheel_speeds_q,df1,curr_time_usec);
            //parse_wheel_speed_dbc_format(df1);
        }
        if(curr_time_usec%break_module_dif==0){
            //printf("create new break message and insert to queue %d \n",curr_time_usec);
            df2=create_break_module(1);
            enqueue(break_module_q,df2,curr_time_usec);
            //parse_brake_dbc_format(df2);
        }
        if(curr_time_usec%power_train_dif==0){
            //printf("create new break powerrain t and insert to queue %d \n",curr_time_usec);
            df3=create_powertrain(10000);
            enqueue(powertrain_q,df3,curr_time_usec);
            //parse_powertrain_dbc_format(df3);
        }

        //trying to transmit a message with the lowest id : powertrain,break,wheel speeds
        if (bus_free==0){
            if(powertrain_q->num_el){
                powertrain_msg++;
                printf("start at %d transmitting power train message:\n",curr_time_usec);
                queue_node* powertrain_node = dequeue(powertrain_q);
                fprintf(sent_msg,"<%d usec>: ",curr_time_usec);
                parse_powertrain_dbc_format(powertrain_node->key,sent_msg);
                delete_node(powertrain_node);
                bus_free=time_to_transfer_power-RESOLUTION;

            }
            else if(break_module_q->num_el){
                break_module_msg++;
                printf("start at %d transmitting break module  message: \n",curr_time_usec);
                queue_node* break_node = dequeue(break_module_q);
                fprintf(sent_msg,"<%d usec>: ",curr_time_usec);
                parse_brake_dbc_format(break_node->key,sent_msg);
                delete_node(break_node);
                bus_free=time_to_transfer_brake-RESOLUTION;


            }
            else if(wheel_speeds_q->num_el){
                wheel_speeds_msg++;
                printf("start at %d transmitting wheel speeds message:\n ",curr_time_usec);
                queue_node* wheel_speeds_node = dequeue(wheel_speeds_q);
                fprintf(sent_msg,"<%d usec>: ",curr_time_usec);
                parse_wheel_speed_dbc_format(wheel_speeds_node->key,sent_msg);
                delete_node(wheel_speeds_node);
                bus_free=time_to_transfer_wheel-RESOLUTION;

            }

        }
        else{
            bus_free-=100;
        }

        curr_time_usec+=100;
    }

    delete_queue(powertrain_q);
    delete_queue(wheel_speeds_q);
    delete_queue(break_module_q);

    fprintf(summary_report, "total sent messages        %d \n",wheel_speeds_msg+break_module_msg+powertrain_msg);
    fprintf(summary_report, "wheel speeds sent messages %d \n",wheel_speeds_msg);
    fprintf(summary_report, "break module sent messages %d \n",break_module_msg);
    fprintf(summary_report, "power train  sent messages %d \n",powertrain_msg);





    return 0;
}