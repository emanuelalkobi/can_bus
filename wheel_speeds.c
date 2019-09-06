//
// Created by emanuel alkobi on 06/09/2019.
//

#include "wheel_speeds.h"




bool wheel_speeds_out_of_bounds(unsigned int  fl,unsigned int fr,unsigned int rl,unsigned int rr){
    if((fl<WHEEL_SPEED_MIN || fl> WHEEL_SPEED_MAX) || (fr<WHEEL_SPEED_MIN || fr> WHEEL_SPEED_MAX) || (rl<WHEEL_SPEED_MIN || rl> WHEEL_SPEED_MAX) || (rr<WHEEL_SPEED_MIN || rr> WHEEL_SPEED_MAX)) return false;
    return true;
}

void insert_wheel_speed_dbc_format( data_frame* data_frame_new,unsigned int fl,unsigned int fr,unsigned int rl,unsigned int rr){
    data_frame_new->data_field[0]= (fl & 0x7f80)>>7                      ;
    data_frame_new->data_field[1]= (fl& 0x7f)<<1     | (fr & 0x4000)>>14 ;
    data_frame_new->data_field[2]= (fr& 0x3fc0)>>6                       ;
    data_frame_new->data_field[3]= (fr & 0x3f)<<2    | (rl & 0x6000)>>13 ;
    data_frame_new->data_field[4]= (rl & 0x1fe0)>>5                      ;
    data_frame_new->data_field[5]= (rl & 0x1f)<<3    | (rr & 0x7000)>>12 ;
    data_frame_new->data_field[6]= (rr & 0xff0)>>4                       ;
    data_frame_new->data_field[7]= (rr & 0xf)<<4                         ;
    return;

}

void parse_wheel_speed_dbc_format(data_frame* data_frame_new, FILE *sent_msg){

    unsigned  int fl_short_new = (data_frame_new->data_field[0])<< 7        | (data_frame_new->data_field[1])>>1                                      ;
    unsigned  int fr_short_new = (data_frame_new->data_field[1] & 0x1)<< 14 | (data_frame_new->data_field[2])<<6 | (data_frame_new->data_field[3])>>2 ;
    unsigned  int rl_short_new = (data_frame_new->data_field[3] & 0x3)<< 13 | (data_frame_new->data_field[4])<<5 | (data_frame_new->data_field[5])>>3 ;
    unsigned  int rr_short_new = (data_frame_new->data_field[5] & 0x7)<< 12 | (data_frame_new->data_field[6])<<4 | (data_frame_new->data_field[7])>>4 ;
    //printf("wheel_speeds message fl  %u kmh , fr %u kmh , rl %u kmh , rr %u kmh    \n", fl_short_new,fr_short_new,rl_short_new,rr_short_new);
    fprintf(sent_msg, "wheel speeds message: fl  %f kmh , fr %f kmh , rl %f kmh , rr %f kmh    \n", fl_short_new*SCALE,fr_short_new*SCALE,rl_short_new*SCALE,rr_short_new*SCALE);
}


data_frame* create_wheel_speeds( unsigned int fl,unsigned int fr,unsigned int rl,unsigned int rr){
    if(!wheel_speeds_out_of_bounds(fl,fr,rl,rr)){
        printf("Wheel speeds value is between 0 to 250/SCALE only\n");
        return NULL;
    }
    data_frame* data_frame_new=create_data_frame(WHEEL_SPEED_ID,WHEEL_SPEED_SIZE);
    if(!data_frame_new){
        return  NULL;
    }
    insert_wheel_speed_dbc_format(data_frame_new,fl,fr,rl,rr);
    //parse_wheel_speed_dbc_format(data_frame_new);




    return data_frame_new;
}

int generate_wheel_speed(int num){
    if (num<=250){
        return(100*num);
    }
    return(-100*num+50000);
    return (num%WHEEL_SPEED_MAX);
}
