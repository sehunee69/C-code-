#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int i, n;
	
	printf("Enter the number of integers: ");
	scanf("%d", &n);
	
	int *ptr = (int *)malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++) {
		printf("Enter an integer: ");
		scanf("%d", ptr + i);
	}
	
	for(i = 0; i < n; i++) {
		printf("%d", *(ptr + i));
		
		if(i != n - 1) {
			printf(", ");
		}
	}
	
	return 0;
}
