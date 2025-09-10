#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header_activity3.h"

void initQueue(FlightQueue *q) {

    q->front = NULL;
    q->rear = NULL;

}
int isQueueEmpty(FlightQueue q) {

    return (q.front == NULL && q.rear == NULL);

}
void enqueueFlight(FlightQueue *q, Flight f) {

    Node *temp = malloc(sizeof(Node));
    if(!temp) return;
    temp->data = f;
    temp->next = NULL;

    if(q->front == NULL) {
        q->front = temp;
    } else {
        q->rear->next = temp;
    }

    q->rear = temp;

    printf("Enqueued Flight:\n");
    displayQueue(f);
}
Flight dequeueFlight(FlightQueue *q) {

    Node *delete;
    Flight temp;
    temp.id = -1;

    if(!isQueueEmpty(*q)) {
        temp = q->front->data;
        delete = q->front;
        q->front = delete->next;
        free(delete);

        if(q->front == NULL) {
            q->rear = NULL;
        }
        printf("Dequeued Flight:\n");
        displayQueue(temp);
        return temp;
    }
    
    return temp;
}
Flight peekQueue(FlightQueue q) {

    Flight temp;
    temp.id = -1;

    if(q.front != NULL) {
        temp = q.front->data;
        return temp;
    }

    return temp;
}

void displayQueue(Flight f) {

    printf("%-5d | %-15s | %-15s | %02d:%02d | %02d:%02d\n",
           f.id, f.origin, f.destination,
           f.departure_time.hours, f.departure_time.minutes,
           f.arrival_time.hours, f.arrival_time.minutes);

}



