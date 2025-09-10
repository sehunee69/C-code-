#ifndef QUEUE_LIST_H_INCLUDED
#define QUEUE_LIST_H_INCLUDED

#define MAX 8

typedef int Data;   

typedef struct {
    Data elems[MAX];
    int front;
    int rear;
} List;

void initQueue(List*);
bool enqueue(List*, Data elems);
bool dequeue(List*);
bool isEmpty(List);
bool isFull(List);
Data front(List);
void display(List);
void visualize(List);

#endif