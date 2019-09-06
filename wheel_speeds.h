//
// Created by emanuel alkobi on 06/09/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data_frame_st.h"

#ifndef CAN_BUS_WHEEL_SPEEDS_H
#define CAN_BUS_WHEEL_SPEEDS_H

#define WHEEL_SPEED_ID   464
#define WHEEL_SPEED_SIZE 8
#define WHEEL_SPEED_MIN  0
#define WHEEL_SPEED_MAX  250



/*
 * Function: wheel_speeds_out_of_bounds
 * ----------------------------
 *   check that al wheel speeds are between WHEEL_SPEED_MIN to WHEEL_SPEED_MAX
 *
 *   fl:   front left wheel speed
 *   fr:   front right wheel speed
 *   rl:   rear  left wheel speed
 *   rr:   rear  right wheel speed
 *
 *  returns: true if all the wheel speeds are in range otherwise return false
 */
bool wheel_speeds_out_of_bounds( double fl,double fr,double rl,double rr);

/*
 * Function: wheel_speeds_out_of_bounds
 * ----------------------------
 *   check that al wheel speeds are between WHEEL_SPEED_MIN to WHEEL_SPEED_MAX
 *
 *   fl:   front left wheel speed
 *   fr:   front right wheel speed
 *   rl:   rear  left wheel speed
 *   rr:   rear  right wheel speed
 *
 *  returns: a pointer to a data frame where the field data_field points to a DBC format for the wheel speeds messages
 */
data_frame* create_wheel_speeds( double fl,double fr,double rl,double rr);

#endif //CAN_BUS_WHEEL_SPEEDS_H
