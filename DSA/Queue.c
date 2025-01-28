#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct {
    int items[max];
    int front, rear;
} Queue;

int isFull(Queue *q);
int isEmpty(Queue *q);

void enQueue(Queue *q, int num){
    if(isFull(q)){
        printf("Queue is full.\n");
    } else {
        if(q->front == -1);
        q->front = 0;
        q->rear++;
        q->items[q->rear] = num;
        printf("%d enqueued.\n", num);
    }
}

int deQueue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1; 
    } else {
        int item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            q->front = q->rear = -1;
        }
        return item;
    }
}

int isFull(Queue *q){
    return q->rear == max - 1;
}

int isEmpty(Queue *q){
    return q->front == -1;
}

int top(Queue *q){
    return q->items[q->front];
}

int main() {
    Queue q;
    int num;
    int choice; 
    q.front = q.rear = -1;
    
    do{
        
    printf("What do you want to do? \n\n[1] Enqueue\n[2] Dequeue\n[3] Top\n[0] Exit\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1: 
            printf("Enter number: ");
            scanf("%d", &num);
            enQueue(&q, num);
            break; 
            
        case 2:
            num = deQueue(&q); 
            if (num != -1) { 
                printf("%d dequeued.\n", num);
            }
            break;
            
        case 3: 
            if (!isEmpty(&q)) { 
                printf("Top element is %d\n", top(&q));
            } else {
                printf("Queue is empty.\n");
            }
            break; 
        
        case 0:
            printf("Exiting...");
            break;
            
        default:
            printf("Invalid choice.\n");
    }
    } while (choice!=0);
    return 0;
}