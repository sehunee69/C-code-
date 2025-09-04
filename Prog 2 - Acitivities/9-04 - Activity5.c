#include <stdio.h> 
#include <string.h>

int main () {
	
	char string[] = "The Quick Brown Fox Jumped over the lazy dog";
	char vowels[100];
	int i, j = 0;
	int count = 0;
	
	
	for(i = 0; string[i] != '\0'; i++) {
		if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u') {
			vowels[j++] = string[i];
		}
	}
	vowels[j] = '\0';
	
	for(i = 0; vowels[i] != '\0'; i++) {
		printf("%c", vowels[i]);
	}
	
	return 0;
	
}
