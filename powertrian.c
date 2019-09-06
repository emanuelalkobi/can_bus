//
// Created by emanuel alkobi on 06/09/2019.
//

#include "powertrian.h"


bool rpm_out_of_bounds(unsigned int rpm){
    if(rpm<RPM_MIN || rpm>RPM_MAX) return false;

    return true;
}


void insert_powertrain_dbc_format( data_frame* data_frame_new,unsigned int rpm){
    data_frame_new->data_field[2]=(rpm & 0x8000) >> 15;
    data_frame_new->data_field[3]=(rpm & 0x3f80) >> 7;
    data_frame_new->data_field[4]=(rpm & 0x7f)<<1;
    return;

}

void parse_powertrain_dbc_format(data_frame* data_frame_new){
    unsigned  int new_rpm=(data_frame_new->data_field[2])<<15 | (data_frame_new->data_field[3])<<7 | (data_frame_new->data_field[4])>>1 ;
    printf("new prm is %d\n",new_rpm);
}


data_frame* create_powertrain( unsigned int rpm){
    if(!rpm_out_of_bounds(rpm)){
        printf("rpm value is between 0 to 15000 only\n");
        return NULL;
    }
    data_frame* data_frame_new=create_data_frame(POWERTRAIN_ID,POWERTRAIN_SIZE);
    if(!data_frame_new){
        return  NULL;
    }

    insert_powertrain_dbc_format(data_frame_new,rpm);
    parse_powertrain_dbc_format(data_frame_new);
    return data_frame_new;
}