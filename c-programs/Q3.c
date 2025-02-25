//Write a function that concatenates two strings using dynamic memory allocation. The code incorrectly allocates memory for the null terminator.
 //Code:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatStrings(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *result = malloc(len1 + len2);
    if (result == NULL) {
        return NULL;
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main() {
    char *str1 = "Hello, ";
    char *str2 = "World!";
    char *combined = concatStrings(str1, str2);
    printf("%s\n", combined);
    free(combined);
    return 0;
}

//Expected Output:

Hello, World!

