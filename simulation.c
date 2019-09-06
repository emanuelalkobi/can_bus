//
// Created by emanuel alkobi on 06/09/2019.
//

#include "simulation.h"



void run_simulation(int stress_factor,int drive_session_time_sec){
    int drive_session_time_usec = USEC * drive_session_time_sec;


    int wheel_speed_freq  = WHEEL_SPEEDS_FREQ*stress_factor;
    int break_module_freq = BREAK_MODULE_FREQ*stress_factor;
    int power_train_freq  = POWERTRAIN_MODULE_FREQ*stress_factor;

    int wheel_speed_dif  = USEC/wheel_speed_freq;
    int break_module_dif = USEC/break_module_freq;
    int power_train_dif  = USEC/power_train_freq;


    int time_to_transfer_wheel= round_resolution(WHEEL_SPEED_BITS_SIZE*USEC/BIT_RATE,RESOLUTION);
    int time_to_transfer_brake= round_resolution(BREAK_MODULE_BITS_SIZE*USEC/BIT_RATE,RESOLUTION);
    int time_to_transfer_power= round_resolution(POWERTRAIN_BITS_SIZE*USEC/BIT_RATE,RESOLUTION);


    //counters for number of messages sent per message type
    int powertrain_msg   = 0;
    int wheel_speeds_msg = 0;
    int break_module_msg = 0;

    //counters for number of messages sent per message queued type
    int powertrain_msg_q   = 0;
    int wheel_speeds_msg_q = 0;
    int break_module_msg_q = 0;

    //counters for jitter per message type
    int powertrain_jitter   = 0;
    int wheel_speeds_jitter = 0;
    int break_module_jitter = 0;

    //define output files stream
    FILE *sent_msg;
    FILE *summary_report;


    sent_msg       = fopen("sent_messages.txt", "w+");
    summary_report = fopen("summary_report.txt", "w+");
    get_headline_sent( sent_msg, drive_session_time_sec, stress_factor, RESOLUTION);

    data_frame* df1;
    data_frame* df2;
    data_frame* df3;


    //queues for each message type
    queue* wheel_speeds_q = new_queue();
    queue* break_module_q = new_queue();
    queue* powertrain_q   = new_queue();


    int curr_time_usec=0;
    int bus_free = 0;

    //value for current generated parameters
    int curr_power_train;
    int curr_wheel_speed;
    int curr_break_module;

    //counters for each message type in order to generate gradual values for simulation
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


    //delete queues after simulation ends
    delete_queue(powertrain_q);
    delete_queue(wheel_speeds_q);
    delete_queue(break_module_q);

    get_headline_report(summary_report,drive_session_time_sec,stress_factor,RESOLUTION);
    get_number_messages_stats(summary_report,wheel_speeds_msg,break_module_msg,powertrain_msg,wheel_speeds_msg_q,break_module_msg_q,powertrain_msg_q);
    get_message_jitter(summary_report,wheel_speeds_jitter,break_module_jitter,powertrain_jitter,wheel_speeds_msg,break_module_msg,powertrain_msg,USEC_TO_MSEC);
    get_average_bandwidth(summary_report,wheel_speeds_msg,powertrain_msg,break_module_msg,drive_session_time_sec);





}