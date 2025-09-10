#include <stdio.h>
#include <stdlib.h>

typedef enum {
    TRUE,
    FALSE
} boolean;

typedef struct node {
    int data;
    struct node *next;
} *List;

boolean isEqualNotSorted(List A, List B);
boolean isEqualSorted(List A, List B);
void sort(List L);


void initList(List *L);
void insertFirst(List *L, int data);
void deleteFirst(List *L);
void populate(List *L, int size);
void printList(List L);
void freeAll(List *L);