#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct {
    int items[max];
    int top;
} Stack;

int isFull(Stack *s);
int isEmpty(Stack *s);

void push(Stack *s, int num){
    if(isFull(s)){
        printf("Stack is full.\n");
    } else {
        s->items[++(s->top)] = num;
        printf("%d pushed.\n", num);
    }
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return -1; 
    } else {
        return s->items[(s->top)--];
    }
}

int isFull(Stack *s){
    return s->top == max - 1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

int top(Stack *s){
    return s->items[s->top];
}

int main() {
    Stack s;
    int num;
    int choice; 
    s.top = -1;
    
    do{
        
    printf("What do you want to do? \n\n[1] Push\n[2] Pop\n[3] Top\n[0] Exit\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1: 
            printf("Enter number: ");
            scanf("%d", &num);
            push(&s, num);
            break; 
            
        case 2:
            num = pop(&s); 
            if (num != -1) { 
                printf("%d popped.\n", num);
            }
            break;
            
        case 3: 
            if (!isEmpty(&s)) { 
                printf("Top element is %d\n", top(&s));
            } else {
                printf("Stack is empty.\n");
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