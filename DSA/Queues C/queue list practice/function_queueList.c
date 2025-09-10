#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_list.h"

void initQueue(List *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(List q) {
    return (q.front == -1);
}

bool isFull(List q) {
    return ((q.rear + 1) % MAX == q.front);
}

bool enqueue(List *q, Data elem) {
    if (isFull(*q)) return false;

    if (isEmpty(*q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->elems[q->rear] = elem;
    return true;
}

bool dequeue(List *q) {
    if (isEmpty(*q)) return false;

    if (q->front == q->rear) {
        // only one element
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return true;
}

Data front(List q) {
    if (!isEmpty(q)) return q.elems[q.front];

    printf("Queue is empty!\n");
    exit(1);
}

void display(List q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = q.front;
    while (1) {
        printf("%d ", q.elems[i]);
        if (i == q.rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void visualize(List q) {
    printf("Queue visualization:\n");
    for (int i = 0; i < MAX; i++) {
        if (!isEmpty(q)) {
            int idx = q.front;
            bool found = false;
            while (1) {
                if (idx == i) {
                    printf("[%d] ", q.elems[idx]);
                    found = true;
                    break;
                }
                if (idx == q.rear) break;
                idx = (idx + 1) % MAX;
            }
            if (!found) printf("[ ] ");
        } else {
            printf("[ ] ");
        }
    }
    printf("\n");
}
