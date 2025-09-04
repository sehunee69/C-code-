#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct 
{
    int x;
    int link;
} NodeType;

typedef struct 
{
    NodeType Nodes[MAX];
    int avail;
} VirtualHeap;

void initL(int *L);
void initializeListV1(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void insertFirst(VirtualHeap *VH, int *L, int x);
void insertLast(VirtualHeap *VH, int *L, int x);
void displayList(VirtualHeap VH, int L);
void tempDisplay(VirtualHeap VH);

int main(void)
{
    int L;
    VirtualHeap VH;

    initL(&L);
    initializeListV1(&VH);
    insertFirst(&VH, &L, 104);
    insertFirst(&VH, &L, 108);
    insertFirst(&VH, &L, 112);
    insertFirst(&VH, &L, 116);
    insertFirst(&VH, &L, 120);

    insertLast(&VH, &L, 90);

    displayList(VH, L);


    return 0;
}

void initL(int *L)
{
    *L = -1;
}

void initializeListV1(VirtualHeap *VH)
{
    int i;
    VH->avail = 0;

    for (i = VH->avail; i < MAX - 1; i++)
    {
        VH->Nodes[i].link = i + 1;
    }

    VH->Nodes[i].link = -1;
}

int allocSpace(VirtualHeap *VH)
{
    int nDx = VH->avail;

    if (nDx != -1) VH->avail = VH->Nodes[nDx].link;

    return nDx;
}

void insertFirst(VirtualHeap *VH, int *L, int x)
{   
    int temp = allocSpace(VH);
    if (VH->avail == -1 || temp == -1) return;
    
    VH->Nodes[temp].x = x;
    VH->Nodes[temp].link = *L;
    *L = temp;

}

void insertLast(VirtualHeap *VH, int *L, int x)
{
    int temp;
    int *trav = L;
    // for (trav = L; VH->Nodes[*(trav + 1)].link != -1; trav = &VH->Nodes[*trav].link){}
    // printf("%d", VH->Nodes[*trav].x);
    for (trav = L; *trav != -1; trav = &VH->Nodes[*trav].link){}
    temp = allocSpace(VH);

    printf("%d %d\n\n", temp, *trav);
    
    // if (VH->avail == -1 || temp == -1) return;

    // VH->Nodes[temp].x = x;
    // VH->Nodes[temp].link = -1;
    // *L = temp;

}

void displayList(VirtualHeap VH, int L)
{
    for (; L != -1; L = VH.Nodes[L].link)
    {
        printf("Data: %d, Link: %d\n", VH.Nodes[L].x, VH.Nodes[L].link);
    }

    printf("\n\n");

}

void tempDisplay(VirtualHeap VH)
{
    int i;

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", VH.Nodes[i].link);
    }
}



