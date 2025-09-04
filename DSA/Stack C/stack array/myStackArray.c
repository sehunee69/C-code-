#include <stdio.h>
#include "myStackA.c"

int main() {
    
    List l;

    initStack(&l);
    push(&l, 10);
    visualize(l);
    push(&l, 20);
    visualize(l);
    push(&l, 30);
    visualize(l);
    
}