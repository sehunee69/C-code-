#include <stdio.h> 

int insertFirst(int arr[], int count);
int insertLast(int arr[], int count);
int deleteFirst(int arr[], int count);
int deleteLast(int arr[], int count);
	
int main() {
	
	int arr[100] = {1, 2, 3, 4, 5};
	int count = 5;
	
	insertFirst(arr, count);
	
	insertLast(arr, count);
	
	
}

int insertFirst(int arr[], int count) {
	
	int i;
	
	for(i = count - 1; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	arr[0] = 10;
	count++;
	
	printf("Insert First: ");
	for(i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}

int insertLast(int arr[], int count) {
    
    int i;
    
    arr[6] = 10;
	count++;
    printf("\nInsert Last: ");
    for(i = 0; i <= count; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}


