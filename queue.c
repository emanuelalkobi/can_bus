//
// Created by emanuel alkobi on 06/09/2019.
//

#include "queue.h"
queue_node* new_node(data_frame* df, unsigned int time){
    queue_node* tmp=(queue_node*)malloc(sizeof( queue_node));
    tmp->key = df;
    tmp->time=time;
    tmp->next = NULL;
    return tmp;
}

queue* new_queue(){
    queue* q = (struct queue*)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    q->num_el=0;
    return q;
}

void enqueue( queue* q, data_frame* df, unsigned int time)
{
    // Create a new LL node
    queue_node* tmp = new_node(df,time);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = tmp;
        q->num_el++;

        return;
    }
    // Add the new node at the end of queue and change rear
    q->rear->next = tmp;
    q->rear = tmp;
    q->num_el++;
}

 queue_node* dequeue( queue* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return NULL;

    // Store previous front and move front one node ahead
    queue_node* tmp = q->front;
    q->front = q->front->next;
    q->num_el--;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
    return tmp;
}

void delete_node(queue_node* node){
    delete_data_frame(node->key);
    free(node);
}

void delete_queue(queue* q){
    //if there are un-sent messages ,delete them and free memory
    while(q->num_el>0){
        queue_node* node = dequeue(q);
        delete_node(node);
    }
    free(q);
}
