//
// Created by emanuel alkobi on 06/09/2019.
//
#include <stdio.h>
#include <stdlib.h>

#include "data_frame_st.h"





data_frame* create_data_frame(int id,int size){

    data_frame* data_frame_new=(data_frame*)malloc(sizeof(data_frame));
    if(!data_frame_new){
        printf("Error in allocation memory-data_frame");
        return NULL;
    }
    data_frame_new->start_of_frame =0;
    data_frame_new->identifier     =id;
    data_frame_new->rtr            =0;
    data_frame_new->ide            =0;
    data_frame_new->r0             =0;
    data_frame_new->dlc            =size;
    data_frame_new->data_field     =(unsigned int*)malloc(size);

    if(!data_frame_new->data_field){
        printf("Error in allocation memory data_frame->data_field");
        return NULL;
    }

    data_frame_new->crc            =0;
    data_frame_new->crc_del        =1;
    data_frame_new->ack_slot       =1;
    data_frame_new->ack_del        =1;
    data_frame_new->eof            =1;

    return data_frame_new;

}

void delete_data_frame(data_frame* data_frame_to_delete){
    free(data_frame_to_delete->data_field);
    free(data_frame_to_delete);
    return;
}
