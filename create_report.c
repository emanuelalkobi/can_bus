//
// Created by emanuel alkobi on 06/09/2019.
//

#include "create_report.h"

void get_number_messages_stats(FILE* summary_report,int wheel_speeds_msg,int break_module_msg,int powertrain_msg,int wheel_speeds_msg_q,int break_module_msg_q,int powertrain_msg_q){


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



}

void get_message_jitter(FILE* summary_report,int wheel_speeds_jitter,int powertrain_jitter,int break_module_jitter,int wheel_speeds_msg,int break_module_msg,int powertrain_msg,int USEC_TO_MSEC){
    fprintf(summary_report, "wheel speeds messages jitter %f msec \n",(float)wheel_speeds_jitter/(USEC_TO_MSEC*wheel_speeds_msg));
    fprintf(summary_report, "break module messages jitter %f msec\n",(float)break_module_jitter/(USEC_TO_MSEC*break_module_msg));
    fprintf(summary_report, "power train  messages jitter %f msec\n",(float)break_module_jitter/(USEC_TO_MSEC*powertrain_msg));

}


void get_average_bandwidth(FILE* summary_report,int wheel_speeds_msg,int powertrain_msg,int break_module_msg,int drive_session_time_sec){
    fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");
    fprintf(summary_report, "average bandwidth %f kbps \n",(float)(wheel_speeds_msg*WHEEL_SPEED_BITS_SIZE+powertrain_msg*POWERTRAIN_BITS_SIZE+break_module_msg*BREAK_MODULE_BITS_SIZE)/(1000*drive_session_time_sec));
    fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");
}


void get_headline_report(FILE* summary_report,int drive_session_time_sec,int stress_factor,int RESOLUTION){
    fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");
    fprintf(summary_report, "summary_report over CAN bus for  %d seconds  stress  factor %d resolution %d usec \n",drive_session_time_sec,stress_factor,RESOLUTION);
    fprintf(summary_report,"---------------------------------------------------------------------------------------------------------------\n");
}

void get_headline_sent(FILE* sent_msg,int drive_session_time_sec,int stress_factor,int RESOLUTION){

    fprintf(sent_msg,"---------------------------------------------------------------------------------------------------------------\n");
    fprintf(sent_msg, "sent messages over CAN bus for  %d seconds  stress  factor %d resolution %d usec \n",drive_session_time_sec,stress_factor,RESOLUTION);
    fprintf(sent_msg,"---------------------------------------------------------------------------------------------------------------\n");
}