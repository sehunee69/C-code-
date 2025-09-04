#include <stdio.h>

typedef struct car{
	
	char *engine;
	char *fuel_type;
	int fuel_tank_cap;
	int seating_cap;
	float city_mileage;
}car;

int main() {
	
	car c1;
	car c2;
	car c3;
	
	printf("Enter Engine type of Car 1: ");
	scanf("%c", &c1.engine);
	printf("Enter Engine type of Car 2: ");
	scanf(" %c", &c2.engine);
	printf("Enter Engine type of Car 3: ");
	scanf("%c", &c3.engine);
	
	printf("Engine type of Car 1: %d", c1.engine);
	printf("Engine type of Car 2: %d", c2.engine);
	printf("Engine type of Car 3: %d", c3.engine);
	
	return 0;
		
}
