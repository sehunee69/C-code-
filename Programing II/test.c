#include <stdio.h>

struct{
	char *engine_type;
} car1, car2;

int main() {
	
	car1.engine_type = "DDis 190 Engine";
	car2.engine_type = "1.2 L Kappa Dual VTVT";		
	printf("Car 1 = %s\n", car1.engine_type);
	printf("Car 2 = %s", car2.engine_type);
	
	return 0;
}
