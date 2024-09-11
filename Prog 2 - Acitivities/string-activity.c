#include <stdio.h> 
#include <string.h>
#include <ctype.h>

void lowerCase(char str[]);
int isReversible(char str1[], char str2[]);

int main() {
	
	char str1[100], str2[100];
	
	printf("Enter first string: ");
	scanf("%s", &str1);
	printf("Enter second string: ");
	scanf("%s", &str2);
	
	lowerCase(str1);
	lowerCase(str2);
	
	if(isReversible(str1, str2)) {
	    printf("Output: True");
	} else {
	    printf("Output: False");
	}
	
	return 0;
}

void lowerCase(char str[]) {
    
    int i;
    
    for(i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isReversible(char str1[], char str2[]) {
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i;
    
    if(len1 != len2) {
        return 0;
    }
    
    for(i = 0; i < len1; i++) {
        if(str1[i] != str2[len2 - i - 1]) {
            return 0;
        }
    }
    
    return 1;
}
