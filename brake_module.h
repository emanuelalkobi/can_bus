//
// Created by emanuel alkobi on 06/09/2019.
//



#ifndef CAN_BUS_BRAKE_MODULE_H
#define CAN_BUS_BRAKE_MODULE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data_frame_st.h"

#define  BREAK_MODULE_FREQ 10
#define BREAK_MODULE_ID 446
#define BREAK_MODULE_SIZE 3
#define BREAK_MODULE_BITS_SIZE 68

#define BREAK_BITS_SIZE

/*
 * Function: create_break_module
 * ----------------------------
 *   create a new break_module message
 *
 *   brake_press:  1 if breaks are press otherwise 0
 *  returns: a pointer to a data frame where the field data_field points to a DBC format for the break module message
 */
data_frame* create_break_module( unsigned int brake_press);


/*
 * Function: insert_brake_dbc_format
 * ----------------------------
 *   insert the data tp data_frame_new in dbc format for wheel speeds
 *
 *   brake_press             :   1 if breaks are press otherwise 0

 *   data_frame_new : the data frame to insert the break module
 *
 */
void insert_brake_dbc_format(data_frame* data_frame_new,unsigned  int brake_press);

/*
 * Function: parse_brake_dbc_format
 * ----------------------------
 *   parse the data stored in the frame based on the dbc format
 *
 *   data_frame_new : the data frame to parse from  the break module
 *   sent_msg       : pointer to a file in order to write to it the output
 */
void parse_brake_dbc_format(data_frame* data_frame_new,FILE *sent_msg);


/*
 * Function: generate_break
 * ----------------------------
 *   generate the break to 0 or 1
 *
 *   num : the current value from where we generate thebreak
 *
 *  returns:break status
 *
 */
int generate_break(int num);


#endif //CAN_BUS_BRAKE_MODULE_H
