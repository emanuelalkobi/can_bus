//
// Created by emanuel alkobi on 06/09/2019.
//

#ifndef CAN_BUS_CREATE_REPORT_H
#define CAN_BUS_CREATE_REPORT_H
#include <stdio.h>
#include "powertrian.h"
#include "brake_module.h"
#include "wheel_speeds.h"


//All these function write the next statistics to the summary_report.txt
//1.number of sent message over the CAN bus
//2.number of queued message over the CAN bus
//3.jitter value per message types
//4.avergae bandwidth

void get_number_messages_stats(FILE* summary_report,int wheel_speeds_msg,int break_module_msg,int powertrain_msg,int wheel_speeds_msg_q,int break_module_msg_q,int powertrain_msg_q);


void get_message_jitter(FILE* summary_report,int wheel_speeds_jitter,int break_module_jitter,int powertrain_jitter,int wheel_speeds_msg,int break_module_msg,int powertrain_msg,int USEC_TO_MSEC);

void get_average_bandwidth(FILE* summary_report,int wheel_speeds_msg,int powertrain_msg,int break_module_msg,int drive_session_time_sec);

void get_headline_report(FILE* summary_report,int drive_session_time_sec,int stress_factor,int RESOLUTION);

void get_headline_sent(FILE* sent_msg,int drive_session_time_sec,int stress_factor,int RESOLUTION);

#endif //CAN_BUS_CREATE_REPORT_H
