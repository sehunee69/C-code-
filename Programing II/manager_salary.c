#include <stdio.h>

struct employee {
	
	char *name;
	char age;
	int salary;
};

int manager() {
	
	struct employee manager;
	
	manager.age = 27;
	
	if(manager.age > 30) {
		manager.salary = 65000;
	} else {
		manager.salary = 55000;
	}
	
	return manager.salary;
}

int main() {
	
	struct employee emp1;
	struct employee emp2;
	
	printf("Enter salary of employee 1: ");
	scanf("%d", &emp1.salary);
	printf("Enter salary of employee 2: ");
	scanf("%d", &emp2.salary);
	
	printf("Salary of Employee 1: %d\n", emp1.salary);
	printf("Salary of Employee 2: %d\n", emp2.salary);
	
	printf("\nSalary of Manager: %d", manager());
	
	return 0;
}
