//
// Created by emanuel alkobi on 06/09/2019.
//

#include "wheel_speeds.h"



bool wheel_speeds_out_of_bounds( double fl,double fr,double rl,double rr){
    if((fl<WHEEL_SPEED_MIN || fl> WHEEL_SPEED_MAX) || (fr<WHEEL_SPEED_MIN || fr> WHEEL_SPEED_MAX) || (rl<WHEEL_SPEED_MIN || rl> WHEEL_SPEED_MAX) || (rr<WHEEL_SPEED_MIN || rr> WHEEL_SPEED_MAX)) return false;
    return true;
}


data_frame* create_wheel_speeds( double fl,double fr,double rl,double rr){
    if(!wheel_speeds_out_of_bounds(fl,fr,rl,rr)){
        printf("Wheel speeds value is between 0 to 250 only\n");
        return NULL;
    }
    data_frame* data_frame_new=create_data_frame(WHEEL_SPEED_ID,WHEEL_SPEED_SIZE);
    
    for(int i=0;i<WHEEL_SPEED_SIZE;i++){
        data_frame_new->data_field[i]=i*123;
    }
    printf("id is %u size is %lu\n",data_frame_new->identifier, sizeof(data_frame_new->data_field));



}