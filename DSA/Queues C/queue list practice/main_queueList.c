#include <stdio.h>
#include "function_queueList.c"

int main() {

    List l;

    initQueue(&l);

    enqueue(&l, 5);
    display(l);
    enqueue(&l, 10);
    enqueue(&l, 15);
    enqueue(&l, 20);
    printf("Front queue: %d\n", front(l));
    dequeue(&l);
    display(l);
    printf("Front queue: %d\n", front(l));

}

