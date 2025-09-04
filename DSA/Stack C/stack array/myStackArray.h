#ifndef MYSTACKARRAY_H_INCLUDED
#define MYSTACKARRAY_H_INCLUDED

typedef int Data;

#define MAX 5

typedef struct {
    Data elems[MAX];
    int top;
} List;

void initStack(List*);
bool push(List*, Data elem);
bool pop(List*);
Data peek(List);
bool isFull(List);
bool isEmpty(List);
void displayStack(List);
void visualize(List);

#endif