#include <stdio.h>
#include <stdlib.h>

int* getOdd(int* arr, int size, int *oddSize);

int* getEven(int* arr, int size, int *evenSize);

int main() {
    
    int i, size, oddSize, evenSize;
    
    printf("Enter size of Array: ");
    scanf("%d", &size);
    
    int* arr = malloc(size * sizeof(int));
    if(arr == NULL) {
        perror("Failed to allocate memory.");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the values:\n");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int *oddNumbers = getOdd(arr, size, &oddSize);
    
    int *evenNumbers = getEven(arr, size, &evenSize);

    printf("Odd Numbers: ");
    for(i = 0; i < oddSize; i++) {
        printf("%d", oddNumbers[i]);
        if(i != evenSize - 1) {
            printf(", ");
        }
    }
    
    printf("\n");
    
    printf("Even Numbers: ");
    for(i = 0; i < evenSize; i++) {
        printf("%d", evenNumbers[i]);
        if(i != evenSize - 1) {
            printf(", ");
        }
    }
    
    printf("\n");
    
    return 0;
    
}

int* getOdd(int* arr, int size, int *oddSize) {
    
    int i;
    
    *oddSize = 0;
    for(i = 0; i < size; i++) {
        if(arr[i] % 2 != 0) {
            (*oddSize)++;
        }
    }
    
    int* oddNumbers = malloc((*oddSize) * sizeof(int));
    if (oddNumbers == NULL) {
        perror("Failed to allocate memory for odd numbers.");
        exit(EXIT_FAILURE);
    }
    
    int j = 0;
    for(i = 0; i < size; i++) {
        if(arr[i] % 2 != 0) {
            oddNumbers[j++] = arr[i];
        }
    }
    
    return oddNumbers;
}

int* getEven(int* arr, int size, int *evenSize) {
    
    int i;
    
    *evenSize = 0;
    for(i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            (*evenSize)++;
        }
    }
    
    int* evenNumbers = malloc((*evenSize) * sizeof(int));
    if(evenNumbers == NULL) {
        perror("Failed to allocate memory for odd numbers.");
        exit(EXIT_FAILURE);
    }
    
    int j = 0;
    for(i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            evenNumbers[j++] = arr[i];
        }
    }
    
    return evenNumbers;
    
}
