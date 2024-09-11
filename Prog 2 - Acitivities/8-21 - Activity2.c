#include <stdio.h>

int main() {
    
    int arr[100];
    int size, i;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    printf("Enter Values: \n");
    
    for(i = 0; i < size; i++) {
    	
    	scanf("%d", &arr[i]);
	}
	
	for(i = 0; i < size; i++) {
		if(arr[i] % 2 == 0) {
			arr[i] *=2;
		} else {
			arr[i] *= 3;
		}
		
		
		printf("%d", arr[i]);
	}
    
    
    return 0;
}
