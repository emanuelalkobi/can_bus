//
// Created by emanuel alkobi on 06/09/2019.
//



#ifndef CAN_BUS_WHEEL_SPEEDS_H
#define CAN_BUS_WHEEL_SPEEDS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data_frame_st.h"

#define WHEEL_SPEED_ID   464
#define WHEEL_SPEED_SIZE 8
#define WHEEL_SPEED_MIN  0
#define WHEEL_SPEED_MAX  250000
#define SCALE            0.01




/*
 * Function: wheel_speeds_out_of_bounds
 * ----------------------------
 *   check that al wheel speeds are between WHEEL_SPEED_MIN to WHEEL_SPEED_MAX
 *
 *   fl:   front left wheel speed
 *   fr:   front right wheel speed
 *   rl:   rear  left wheel speed
 *   rr:   rear  right wheel speed
 *   wheel speeds need to be multiplied by SCALE(0.01) to get real value
 *   returns: true if all the wheel speeds are in range otherwise return false
 */
bool wheel_speeds_out_of_bounds( unsigned int fl,unsigned int fr,unsigned int rl,unsigned int rr);

/*
 * Function: create_wheel_speeds
 * ----------------------------
 *   create a new wheel_speeds message
 *
 *   fl:   front left wheel speed
 *   fr:   front right wheel speed
 *   rl:   rear  left wheel speed
 *   rr:   rear  right wheel speed
 *
 *  returns: a pointer to a data frame where the field data_field points to a DBC format for the wheel speeds messages
 */
data_frame* create_wheel_speeds( unsigned int fl,unsigned int fr,unsigned int rl,unsigned int rr);


/*
 * Function: insert_wheel_speed_dbc_format
 * ----------------------------
 *   insert the data tp data_frame_new in dbc format for wheel speeds
 *
 *   fl             :   front left wheel speed
 *   fr             :   front right wheel speed
 *   rl             :   rear  left wheel speed
 *   rr             :   rear  right wheel speed
 *   data_frame_new : the data frame to insert the wheel speeds
 *
 */
void insert_wheel_speed_dbc_format( data_frame* data_frame_new,unsigned int fl,unsigned int fr,unsigned int rl,unsigned int rr);

/*
 * Function: parse_wheel_speed_dbc_format
 * ----------------------------
 *   parse the data stored in the frame based on the dbc format
 *
 *   data_frame_new : the data frame to parse from  the wheel speeds
 *
 */
void parse_wheel_speed_dbc_format(data_frame* data_frame_new);



#endif //CAN_BUS_WHEEL_SPEEDS_H
