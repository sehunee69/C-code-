#include <stdio.h>

void getSum(int x, int y, int *sum);

int main() {
	
	int x, y sum = 0;
	
	printf("x = ");
	scanf("%d", &x);
	printf("y = ");
	scanf("%d", &y);
	
	getSum(x,y, &sum);
	
	printf("Sum = %d", sum);
	
	return 0;
	
}

void getSum(int x, int y, int *sum) {
	
	*sum = x + y;
}
