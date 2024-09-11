#include <stdio.h>
#include <stdlib.h>

void freeAlloc(int *ptr);

int* allocateMemory(int size);

int* calculateSize();

int main() {
    
    int *ptr;
    int *size;
    
    size = calculateSize();
    
    ptr = allocateMemory(size);
    
    freeAlloc(ptr);
    
    size = calculateSize();
    
    ptr = allocateMemory(size);
    
    freeAlloc(ptr);

    return 0;
}

void freeAlloc(int *ptr) {
    
    free(ptr);
    
}

int* allocateMemory(int size) {
    
    int i;
    int *ptr;
    
    ptr = (int *)malloc(size * sizeof(int));
    
    if(ptr == NULL) {
        printf("Memory Allocation failed");
        exit(1);
    }
    
    for(i = 0; i < size; i++) {
        printf("Enter integer: ");
        scanf("%d", ptr + i);
    }
    
    for(i = 0; i < size; i++) {
        printf("%d ", *(ptr + i));
    }
    
    printf("\n");
    
    return ptr;
}

int* calculateSize() {
	
	int s;
	
	printf("Enter size: ");  
	scanf("%d", &s);
	
	return s;
}
