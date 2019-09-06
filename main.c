#include <stdio.h>
#include "func.h"



#define  WHEEL_SPEEDS_FREQ 100
#define  BREAK_MODULE_FREQ 10
#define  POWER_TRAIN_FREQ  25


int main() {
    printf("Hello, World!\n");

    //program parameters
    int drive_session_time_sec = 1800;
    int drive_session_time_usec=1e6*drive_session_time_sec;

    int stress_factor=1;

    printf("drive time in sec %d\n",drive_session_time_sec);
    printf("drive time in usec %d\n",drive_session_time_usec);







    return 0;
}