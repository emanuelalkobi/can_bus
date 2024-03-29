//
// Created by emanuel alkobi on 06/09/2019.
//

#ifndef CAN_BUS_POWERTRIAN_H
#define CAN_BUS_POWERTRIAN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data_frame_st.h"

#define  POWERTRAIN_MODULE_FREQ  25
#define POWERTRAIN_ID   464
#define POWERTRAIN_SIZE  8
#define RPM_MIN  0
#define RPM_MAX  15000
#define POWERTRAIN_BITS_SIZE 108

/*
 * Function: create_powertrain
 * ----------------------------
 *   create a new wheel_speeds message
 *
 *   rpm
 *
 *  returns: a pointer to a data frame where the field data_field points to a DBC format for the powertrain messages
 */
data_frame* create_powertrain( unsigned int rpm);

/*
 * Function: rpm_out_of_bounds
 * ----------------------------
 *   check that al powertrain is   between RPM_MIN to RPM_MAX
 *
 *   rpm
 *   returns: true if powertrain is in range otherwise return false
 */
bool rpm_out_of_bounds(unsigned int rpm);


/*
 * Function: parse_powertrain_dbc_format
 * ----------------------------
 *   parse the data stored in the frame based on the dbc format
 *
 *   data_frame_new : the data frame to parse from  the powertrain
 *   sent_msg       : pointer to a file in order to write to it the output
 *
 */
void parse_powertrain_dbc_format(data_frame* data_frame_new, FILE *sent_msg);


/*
 * Function: insert_powertrain_dbc_format
 * ----------------------------
 *   insert the data to data_frame_new in dbc format for powertrain
 *
 *   prm
 *   data_frame_new : the data frame to insert the powertrain
 *
 */
void insert_powertrain_dbc_format( data_frame* data_frame_new,unsigned int rpm);


/*
 * Function: generate_powertrain
 * ----------------------------
 *   generate the powet train from 0kmh to 15000 rpm
 *
 *   num : the current value from where we generate the power train
 *
 *  returns:power train rpm
 *
 */
int generate_powertrain(int num);

#endif //CAN_BUS_POWERTRIAN_H
