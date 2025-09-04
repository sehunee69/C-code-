#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int List;

typedef struct {
    int elem;
    int next;
} Node;

typedef struct {
    Node space[MAX];
    int avail;
} VSpace;

void initVSpace(VSpace *vs);
int allocSpace(VSpace *vs);
void insertFront(VSpace *vs, List *list, int elem);
void insertLast(VSpace *vs, List *list, int elem);
void displayList(VSpace vs, List list);
void visualizeVHeap(VSpace vs);

int main() {
    VSpace virtualHeap;
    List myList = -1;
    List list2 = -1;
    
    initVSpace(&virtualHeap);
    
    displayList(virtualHeap, myList);
    displayList(virtualHeap, list2);
    visualizeVHeap(virtualHeap);
    insertFront(&virtualHeap, &myList, 10);
    displayList(virtualHeap, myList);
    displayList(virtualHeap, list2);
    visualizeVHeap(virtualHeap);
    insertFront(&virtualHeap, &list2, 6);
    displayList(virtualHeap, myList);
    displayList(virtualHeap, list2);
    visualizeVHeap(virtualHeap);
    insertFront(&virtualHeap, &myList, 4);
    displayList(virtualHeap, myList);
    displayList(virtualHeap, list2);
    visualizeVHeap(virtualHeap);

    insertLast(&virtualHeap, &list2, 7);
    displayList(virtualHeap, myList);
    displayList(virtualHeap, list2);
    visualizeVHeap(virtualHeap);
    insertLast(&virtualHeap, &list2, 6);
    displayList(virtualHeap, myList);
    displayList(virtualHeap, list2);
    visualizeVHeap(virtualHeap);
    
}

void initVSpace(VSpace *vs) {
    for(int i = MAX - 1; i >= 0; --i) {
        vs->space[i].elem = 0;
        vs->space[i].next = i - 1;
    }
    vs->avail = MAX - 1;
}

int allocSpace(VSpace *vs) {
    int avail = vs->avail;
    if(avail != -1) {
        vs->avail = vs->space[avail].next;
    }
    return avail;
}

void insertFront(VSpace *vs, List *list, int elem) {
    int temp = allocSpace(vs);
    
    if(temp != -1) {
        vs->space[temp].elem = elem;
        vs->space[temp].next = *list;
        *list = temp;
    }
}

void insertLast(VSpace *vs, List *list, int elem) {
    int temp = allocSpace(vs);
    int trav;

    if(temp == -1) {
        exit(1);
    }

    for(trav = *list; vs->space[trav].next != -1; trav = vs->space[trav].next) {}

    vs->space[temp].elem = elem;
    vs->space[temp].next = -1;

    vs->space[trav].next = temp;
}

void displayList(VSpace vs, List list) {
    printf("LIST{");
    for(int i = list; i != -1; i = vs.space[i].next) {
        printf("%d", vs.space[i].elem);
        if(vs.space[i].next != -1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void visualizeVHeap(VSpace vs) {
    printf("%10s | %10s | %s\n", "INDEX", "ELEM", "NEXT");
    for(int i = 0; i < MAX; ++i) {
        if(vs.space[i].elem != 0) {
            printf("%10d | %10d | %d\n", i, vs.space[i].elem, vs.space[i].next);
        } else {
            printf("%10d | %10s | %d\n", i, "", vs.space[i].next);
        }
    }
    printf("Avail: %d\n", vs.avail);
}