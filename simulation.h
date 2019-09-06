//
// Created by emanuel alkobi on 06/09/2019.
//

#ifndef CAN_BUS_SIMULATION_H
#define CAN_BUS_SIMULATION_H

#include <stdio.h>

#include "data_frame_st.h"
#include "wheel_speeds.h"
#include "brake_module.h"
#include "powertrian.h"
#include "queue.h"
#include "create_report.h"

#define USEC 1000000
#define RESOLUTION 100
#define USEC_TO_MSEC 1000
#define BIT_RATE 125000
#define USER_PARAMS 2

/*
 * Function: run_simulation
 * ----------------------------
 *   run the can bus simulation
 *
 *   stress_factor           : the strees value for simulation
 *   drive_session_time_sec  : simulation time
 *
 *
 */
void run_simulation(int stress_factor,int drive_session_time_sec);

#endif //CAN_BUS_SIMULATION_H
