#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lower(char str[]);
int compare(char str1[], char str2[]);
int compare2(char str1[], char str2[]);

int main() {
    
    char str1[100];
    char str2[100];
    
    printf("Enter string 1: ");
    scanf(" %[^\n]s", &str1);
    printf("Enter string 2: ");
    scanf(" %[^\n]s", &str2);
    
    lower(str1);
    lower(str2);
    
    if(compare(str1, str2)) {
        printf("Output: True");
    } else {
        if(compare2(str1, str2)) {
            printf("Output: True");
        } else {
            printf("Output: False");
        }
    }
    
    return 0;
    
}

void lower(char str[]) {
    
    int i;
    
    for(i = 0; i < str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    
}

int compare(char str1[], char str2[]) {
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j;
    
    if(len1 != len2) {
        return 0;
    }
    
    j = 0;
    for(i = len1; i > 0; i--) {
        if(str1[j] != str2[i - 1]) {
            return 0;
        }
        j++;
    }
    
    return 1;
}

int compare2(char str1[], char str2[]) {
    
    int len = strlen(str1);
    int i;
    
    for(i = 0; i < len; i++) {
        if(str1[i] != str2[i]) {
            return 0;
        }
    }
    
    return 1;
}

