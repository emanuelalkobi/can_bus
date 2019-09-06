//
// Created by emanuel alkobi on 06/09/2019.
//

#include "brake_module.h"
void insert_brake_dbc_format(data_frame* data_frame_new,unsigned  int brake_press){
    data_frame_new->data_field[0]=brake_press<<3;
    return;
}
void parse_brake_dbc_format(data_frame* data_frame_new){
    unsigned break_module_new=data_frame_new->data_field[0]>>3;
    printf("break status is  %d \n",break_module_new);
    return;

}


data_frame* create_break_module( unsigned int brake_press){
    if(brake_press!=0 && brake_press!=1){
        printf("brake press value is  0 or 1  only\n");
        return NULL;
    }
    data_frame* data_frame_new=create_data_frame(BREAK_MODULE_ID,BREAK_MODULE_SIZE);
    if(!data_frame_new){
        return  NULL;
    }
    insert_brake_dbc_format(data_frame_new,brake_press);




    return data_frame_new;
}