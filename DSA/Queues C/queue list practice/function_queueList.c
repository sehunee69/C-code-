#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue_list.h"

void initQueue(List *q) {
    q->rear = -1;
    q->front = 0;
}
bool enqueue(List *q, Data elems) {
    if((q->rear + 2) % MAX != q->front) {
        q->rear = (q->rear + 1) % MAX;
        q->elems[q->rear] = elems;
        return true;
    } 

    return false;
}
bool dequeue(List *q) {
    if(!isEmpty(*q)) {
        return false;
    }
    
    if(q->rear == q->front) {
        q->front = q->rear - 1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    return true;
    
}
bool isEmpty(List q) {
    return q.front == 1;

}
bool isFull(List q) {
    return ((q.front == 0 && q.rear == MAX - 1) || (q.rear + 1) % MAX == q.front);

}
void front(List) {

}
void display(List) {

}
void visualize(List) {

}