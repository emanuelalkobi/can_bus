//
// Created by emanuel alkobi on 06/09/2019.
//


//The data frame is the only frame for actual data transmission.

#ifndef CAN_BUS_DATA_FRAME_ST_H
#define CAN_BUS_DATA_FRAME_ST_H

typedef  struct  {
    unsigned int  start_of_frame : 1;  //Denotes the start of frame transmission
    unsigned int  identifier     : 11; //A (unique) identifier which also represents the message priority
    unsigned int  rtr            : 1;  //Must be dominant (0) for data frames and recessive (1) for remote request frames
    unsigned int  ide            : 1;  //Must be dominant (0) for base frame format with 11-bit identifiers
    unsigned int  r0             : 1;  //Reserved bit. Must be dominant (0), but accepted as either dominant or recessive.
    unsigned int  dlc            : 4;  //Number of bytes of data (0–8 bytes)
    unsigned char* data_field     ;     //Data to be transmitted (length in bytes dictated by DLC field).Pointer as his size depends on dlc value;
    unsigned int  crc            : 15; //Cyclic redundancy check
    unsigned int  crc_del        : 1;  //Must be recessive (1)
    unsigned int  ack_slot       : 1;  //Transmitter sends recessive (1) and any receiver can assert a dominant (0)
    unsigned int  ack_del        : 1;  //Must be recessive (1)
    unsigned int  eof            : 7;  //Must be recessive (1)
}data_frame ;



/*
 * Function: create_data_frame
 * ----------------------------
 *   create a CAN bus data frame and set his values.allocte memory to the struct.
 *
 *   id:   identifier of the current data frame
 *   size: number of bytes of the data
 *
 *   returns: a pointer to the data frame
 */
data_frame* create_data_frame(int id,int size);



/*
 * Function: delete_data_frame
 * ----------------------------
 *   free the memory allocated to the struct
 *
 *   data_frame_to_delete:   pointer to the data frame to be deleted
 *
 */
void delete_data_frame(data_frame* data_frame_to_delete);

#endif //CAN_BUS_DATA_FRAME_ST_H



