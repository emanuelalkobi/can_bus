#include <stdio.h>

#include "data_frame_st.h"
#include "wheel_speeds.h"
#include "brake_module.h"
#include "powertrian.h"


#define  WHEEL_SPEEDS_FREQ 100
#define  BREAK_MODULE_FREQ 10
#define  POWERTRAIN_MODULE_FREQ  25





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
    data_frame* df1=create_wheel_speeds(5000,7500,10000,12500);
    data_frame* df2=create_break_module(1);
    data_frame* df3=create_powertrain(14000);
    printf("------\n");

    printf("drive time in sec %d\n",drive_session_time_sec);
    printf("drive time in usec %d\n",drive_session_time_usec);

    int curr_time_usec=0;

    while(curr_time_usec<drive_session_time_usec){
        break;
    }







    return 0;
}