#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parentheses.h"

#define MAX 50

void initStack(Stack *s) {
    s->top = -1;
}

bool isValidParentheses(char parentheses[]) {

    Stack s;
    initStack(&s);

    for(int i = 0; parentheses[i] != '\0'; i++) {
        char c = parentheses[i];

        if(c == '(' || c == '{' || c == '[') {
            push(&s, c);
        } else if(c == ')' || c == '}' || c == ']') {
            
            if(isEmpty(s)) {
                return false;
            }

            char t = top(s);
            if(t == '(' && c != ')' || t == '{' && c != '}' || t == '[' && c != ']') {
                return false;
            }

            pop(&s);
        }
    }

    return true;
}

bool isFull(Stack s) {
    return (s.top == MAX - 1) ? true : false;
}

bool isEmpty(Stack s) {
    return (s.top == -1) ? true : false;
}

void push(Stack *s, char data) {
    if(!isFull(*s)) {
        s->elem[++s->top] = data;
    }
}

void pop(Stack *s) {
    if(!isEmpty(*s)) {
        s->top--;
    }
}

char top(Stack s) {
    char d = '\0';
    return (!isEmpty(s)) ? s.elem[s.top] : d;
}


