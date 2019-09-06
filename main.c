#include <stdio.h>

#include "data_frame_st.h"
#include "wheel_speeds.h"
#include "brake_module.h"
#include "powertrian.h"
#include "queue.h"


#define USEC 1000000
#define RESOLUTION 100
#define USEC_TO_MSEC 1000
#define BIT_RATE 125000

int round_resolution(int num,int res){
    int tmp=(num/res)*res+res;
    return tmp;
}

int main() {

    //program parameters

    int drive_session_time_sec  = 600;
    int drive_session_time_usec = USEC * drive_session_time_sec;

    int stress_factor=1;

    int wheel_speed_freq  = WHEEL_SPEEDS_FREQ*stress_factor;
    int break_module_freq = BREAK_MODULE_FREQ*stress_factor;
    int power_train_freq  = POWERTRAIN_MODULE_FREQ*stress_factor;

    int wheel_speed_dif  = USEC/wheel_speed_freq;
    int break_module_dif = USEC/break_module_freq;
    int power_train_dif  = USEC/power_train_freq;


    int time_to_transfer_wheel= round_resolution(WHEEL_SPEED_BITS_SIZE*USEC/BIT_RATE,RESOLUTION);
    int time_to_transfer_brake= round_resolution(BREAK_MODULE_BITS_SIZE*USEC/BIT_RATE,RESOLUTION);
    int time_to_transfer_power= round_resolution(POWERTRAIN_BITS_SIZE*USEC/BIT_RATE,RESOLUTION);

    int powertrain_msg   = 0;
    int wheel_speeds_msg = 0;
    int break_module_msg = 0;

    int powertrain_msg_q   = 0;
    int wheel_speeds_msg_q = 0;
    int break_module_msg_q = 0;

    int powertrain_jitter   = 0;
    int wheel_speeds_jitter = 0;
    int break_module_jitter = 0;

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

    data_frame* df1;
    data_frame* df2;
    data_frame* df3;



    queue* wheel_speeds_q = new_queue();
    queue* break_module_q = new_queue();
    queue* powertrain_q   = new_queue();


    int curr_time_usec=0;
    int bus_free = 0;

    int curr_power_train;
    int curr_wheel_speed;
    int curr_break_module;


    printf("----------------------------------------------------------\n");
    printf("simulation started\n");
    printf("----------------------------------------------------------\n");

    int wheel_speed_ctr=0;
    int powertrain_ctr=0;
    int break_module_ctr=0;
    
    while(curr_time_usec<drive_session_time_usec){
        if(curr_time_usec%wheel_speed_dif==0){

            wheel_speeds_msg_q++;
            curr_wheel_speed=generate_wheel_speed(wheel_speed_ctr);
            df1=create_wheel_speeds(curr_wheel_speed,curr_wheel_speed,curr_wheel_speed,curr_wheel_speed);
            enqueue(wheel_speeds_q,df1,curr_time_usec);
            wheel_speed_ctr++;
            wheel_speed_ctr=wheel_speed_ctr%500;
        }
        if(curr_time_usec%break_module_dif==0){
            break_module_msg_q++;
            curr_break_module=generate_break(break_module_ctr);
            df2=create_break_module(curr_break_module);
            enqueue(break_module_q,df2,curr_time_usec);
            break_module_ctr++;
            break_module_ctr=break_module_ctr%50;
        }
        if(curr_time_usec%power_train_dif==0){
            powertrain_msg_q++;
            curr_power_train=generate_powertrain(powertrain_ctr);
            df3=create_powertrain(curr_power_train);
            enqueue(powertrain_q,df3,curr_time_usec);
            powertrain_ctr++;
            powertrain_ctr=powertrain_ctr%125;
        }


        //trying to transmit a message with the lowest id : powertrain,break,wheel speeds
        if (bus_free==0){
            if(powertrain_q->num_el){
                powertrain_msg++;
                queue_node* powertrain_node = dequeue(powertrain_q);
                powertrain_jitter+=curr_time_usec-powertrain_node->time;
                fprintf(sent_msg,"<%d usec>: ",curr_time_usec);
                parse_powertrain_dbc_format(powertrain_node->key,sent_msg);
                delete_node(powertrain_node);
                bus_free=time_to_transfer_power-RESOLUTION;

            }
            else if(break_module_q->num_el){
                break_module_msg++;
                queue_node* break_node = dequeue(break_module_q);
                break_module_jitter+=curr_time_usec-break_node->time;
                fprintf(sent_msg,"<%d usec>: ",curr_time_usec);
                parse_brake_dbc_format(break_node->key,sent_msg);
                delete_node(break_node);
                bus_free=time_to_transfer_brake-RESOLUTION;


            }
            else if(wheel_speeds_q->num_el){
                wheel_speeds_msg++;
                queue_node* wheel_speeds_node = dequeue(wheel_speeds_q);
                wheel_speeds_jitter+=curr_time_usec-wheel_speeds_node->time;
                fprintf(sent_msg,"<%d usec>: ",curr_time_usec);
                parse_wheel_speed_dbc_format(wheel_speeds_node->key,sent_msg);
                delete_node(wheel_speeds_node);
                bus_free=time_to_transfer_wheel-RESOLUTION;

            }

        }
        else{
            bus_free-=RESOLUTION;
        }

        curr_time_usec+=RESOLUTION;
    }


    delete_queue(powertrain_q);
    delete_queue(wheel_speeds_q);
    delete_queue(break_module_q);

    int total_message_q =wheel_speeds_msg_q+break_module_msg_q+powertrain_msg_q;
    int total_message_sent=wheel_speeds_msg+break_module_msg+powertrain_msg;
    fprintf(summary_report, "total sent messages        %d \n",wheel_speeds_msg+break_module_msg+powertrain_msg);
    fprintf(summary_report, "wheel speeds sent messages %d \n",wheel_speeds_msg);
    fprintf(summary_report, "break module sent messages %d \n",break_module_msg);
    fprintf(summary_report, "power train  sent messages %d \n",powertrain_msg);

    fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");

    fprintf(summary_report, "total queued messages        %d \n",wheel_speeds_msg_q+break_module_msg_q+powertrain_msg_q);
    fprintf(summary_report, "wheel speeds queued messages %d \n",wheel_speeds_msg_q);
    fprintf(summary_report, "break module queued messages %d \n",break_module_msg_q);
    fprintf(summary_report, "power train  queued messages %d \n",powertrain_msg_q);

    fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");

    if(total_message_q!=total_message_sent){
        fprintf(summary_report, "ERROR THERE WERE MESSAGE THAT WERE NOT SENT DURING THE SIMULATION TIME \n");
        fprintf(summary_report, "total queued messages that were not sent           %d \n",total_message_q-total_message_sent);
        fprintf(summary_report, "wheel speeds queued messages that were not sent    %d \n",wheel_speeds_msg_q-wheel_speeds_msg);
        fprintf(summary_report, "break module queued messages that were not sent    %d \n",break_module_msg_q-break_module_msg);
        fprintf(summary_report, "power train  queued messages that were not sent    %d \n",powertrain_msg_q-powertrain_msg);

        fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");
    }


    fprintf(summary_report, "wheel speeds messages jitter %f msec \n",(float)wheel_speeds_jitter/(USEC_TO_MSEC*wheel_speeds_msg));
    fprintf(summary_report, "break module messages jitter %f msec\n",(float)break_module_jitter/(USEC_TO_MSEC*break_module_msg));
    fprintf(summary_report, "power train  messages jitter %f msec\n",(float)break_module_jitter/(USEC_TO_MSEC*powertrain_msg));

    fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");

    fprintf(summary_report, "average bandwidth %f kbps \n",(float)(wheel_speeds_msg*WHEEL_SPEED_BITS_SIZE+powertrain_msg*POWERTRAIN_BITS_SIZE+break_module_msg*BREAK_MODULE_BITS_SIZE)/(1000*drive_session_time_sec));
    fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");

    printf("----------------------------------------------------------\n");
    printf("simulation ended\n");
    printf("----------------------------------------------------------\n");




    return 0;
}