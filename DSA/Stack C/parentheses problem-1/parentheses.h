#ifndef PARENTHESES_H_INCLUDED
#define PARENTHESES_H_INCLUDED

#define MAX 50

typedef struct {
    char elem[MAX];
    int top;
} Stack;

void initStack(Stack*);
bool isValidParentheses(char parentheses[]);
void push(Stack*, char data);
void pop(Stack*);
bool isEmpty(Stack);
bool isFull(Stack);
char top(Stack);

#endif





