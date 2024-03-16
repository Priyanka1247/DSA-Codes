#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100


void concatenateStrings(char result[], const char str1[], const char str2[]) {
    strcpy(result, str1);
    strcat(result, str2);
}


void copyString(char dest[], const char src[]) {
    strcpy(dest, src);
}


int compareStrings(const char str1[], const char str2[]) {
    return strcmp(str1, str2);
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH], result[MAX_LENGTH];

    printf("Enter the first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(str2, MAX_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = '\0';


    concatenateStrings(result, str1, str2);
    printf("Concatenated string: %s\n", result);


    char copied[MAX_LENGTH];
    copyString(copied, str1);
    printf("Copied string: %s\n", copied);


    int comparison = compareStrings(str1, str2);
    if (comparison == 0)
        printf("The strings are equal.\n");
    else if (comparison < 0)
        printf("The first string is lexicographically smaller than the second string.\n");
    else
        printf("The first string is lexicographically larger than the second string.\n");

    return 0;
}
