#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data_frame_st.h"
#include "wheel_speeds.h"

#define  WHEEL_SPEEDS_FREQ 100
#define  BREAK_MODULE_FREQ 10
#define  POWERTRAIN_MODULE_FREQ  25


#define BREAK_MODULE_ID 446
#define POWERTRAIN_DATA 380



int main() {

    //program parameters

    int drive_session_time_sec  = 1800;
    int drive_session_time_usec = 1e6 * drive_session_time_sec;

    int stress_factor=1;

    int wheel_speed_freq  = WHEEL_SPEEDS_FREQ*stress_factor;
    int break_module_freq = BREAK_MODULE_FREQ*stress_factor;
    int power_train_freq  = POWERTRAIN_MODULE_FREQ*stress_factor;

    int bit_rate=125*1e3; // default bit rate on  CANopen 125 kbit/s


    printf("------\n");
    data_frame* df=create_wheel_speeds(5000,7500,10000,12500);
    printf("------\n");

    printf("drive time in sec %d\n",drive_session_time_sec);
    printf("drive time in usec %d\n",drive_session_time_usec);

    int curr_time_usec=0;

    while(curr_time_usec<drive_session_time_usec){
        break;
    }







    return 0;
}