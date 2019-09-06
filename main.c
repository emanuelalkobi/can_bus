#include <stdio.h>

#include "data_frame_st.h"
#include "wheel_speeds.h"
#include "brake_module.h"
#include "powertrian.h"
#include "queue.h"
#include "create_report.h"
#include "simulation.h"

#define USEC 1000000
#define RESOLUTION 100
#define USEC_TO_MSEC 1000
#define BIT_RATE 125000
#define USER_PARAMS 2





int main() {


    //program parameters
    int default_params;
    int drive_session_time_sec=600 ;
    int stress_factor=1;


    printf( "Simulation menu:\n1.run with default values\n2.choose simulation parameters :\n");
    scanf(" %d", &default_params);
    if(default_params==USER_PARAMS){
        printf("Enter simulation time in seconds between 0 to 1800\n");
        scanf(" %d", &drive_session_time_sec);
        printf("Enter simulation stress value between 1 to 20\n");
        scanf(" %d", &stress_factor);
    }

    printf("----------------------------------------------------------\n");
    printf("simulation started\n");
    printf("----------------------------------------------------------\n");

    run_simulation(stress_factor,drive_session_time_sec);

    printf("----------------------------------------------------------\n");
    printf("simulation ended\n");
    printf("----------------------------------------------------------\n");




    return 0;
}