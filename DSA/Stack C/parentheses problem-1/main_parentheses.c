#include <stdio.h>
#include "func_parentheses.c"

int main() {

    char parentheses[256];

    printf("Enter Parentheses: ");
    scanf("%s", parentheses);

    printf("The parentheses is %s", (isValidParentheses(parentheses)) ? "VALID" : "INVALID");

    return 0;
}