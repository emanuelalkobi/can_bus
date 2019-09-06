//
// Created by emanuel alkobi on 06/09/2019.
// based on :
// https://www.geeksforgeeks.org/queue-set-2-linked-list-implementation/
//

#ifndef CAN_BUS_QUEUE_H
#define CAN_BUS_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "data_frame_st.h"



typedef struct queue_node{
    struct queue_node* next;
    data_frame* key;
    unsigned int time;

}queue_node;

typedef struct queue   {
    queue_node  *front, *rear;
    unsigned identifier;
    unsigned int num_el;
} queue ;


/*
 * Function: new_node
 * ----------------------------
 *   create a new node for the queue
 *
 *   df : the data frame to insert to the node
 *   time: the original time the message(node) was created
 *
 *   returns: pointer to the new node
 */
queue_node* new_node(data_frame* df, unsigned int time);


/*
 * Function: new_queue
 * ----------------------------
 *   create a new queue
 *
 *   returns: pointer to the new queue
 */
queue* new_queue();


/*
 * Function: enQueue
 * ----------------------------
 *   insert  a new node to the queue
 *   df : the data frame to insert to the node
 *   time: the original time the message(node) was created
 *
 */
void enqueue( queue* q, data_frame* df, unsigned int time);

/*
 * Function: deQueue
 * ----------------------------
 *   remove   a  node from the queue
 *
 *  returns: pointer to the removed node
 */
queue_node* dequeue( queue* q);


/*
 * Function: delete_node
 * ----------------------------
 *   free memory allocated to a node
 *   node : pointer to the deleted node
 *
 */
void delete_node(queue_node* node);


/*
 * Function: delete_queue
 * ----------------------------
 *   free memory allocated to a queue
 *   node : pointer to the deleted queue
 *
 */
void delete_queue(queue* q);






#endif //CAN_BUS_QUEUE_H
