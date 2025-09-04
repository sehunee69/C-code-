#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "myStackArray.h"


void initStack(List *a) {
    a->top = -1;
}

bool push(List *a, Data elem) {
    
    if(isFull(*a)) {
        return false;
    }

    a->elems[++a->top] = elem;

    displayStack(*a);
    return true;
    
}

bool pop(List *a) {
    
    if(isEmpty(*a)) {
        return false;
    }

    a->top--;

    return true;
}

Data peek(List a) {
    
    if (isEmpty(a)) {
        printf("Emtpy Stack");
        return 0;
    }

    return a.elems[a.top];
}

bool isFull(List a) {
    return a.top == MAX;
}

bool isEmpty(List a) {
    return a.top == -1;
}

void displayStack(List s) {
    
    printf("{");
    while(!isEmpty(s)) {
        printf("%d ", peek(s));
        pop(&s);
    }
    printf("}\n");
}

void visualize(List s) {
    printf("%10s | %10s | %s\n", "INDEX", "DATA", "MARKER");
    for(int i = MAX - 1; i >= 0; --i) {
        printf("%10d |", i);
        if(i > s.top) {
            printf("%10s | %10s\n", "???", "");
        } else {
            printf("%10d |", s.elems[i]);
            printf("%s\n", (s.top == i) ? " Top" : "");
            }
        }
        printf("\n");

        displayStack(s);
    }
    



