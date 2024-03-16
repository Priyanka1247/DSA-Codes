#include <stdio.h>
#include <string.h>

// Function to check if a number is a palindrome
int isPalindromeNumber(int num) {
    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return originalNum == reversedNum;
}

// Function to check if a string is a palindrome
int isPalindromeString(char *str) {
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j])
            return 0; // Not a palindrome
    }

    return 1; // Palindrome
}

int main() {
    int num;
    char str[100];

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindromeNumber(num))
        printf("%d is a palindrome number.\n", num);
    else
        printf("%d is not a palindrome number.\n", num);

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindromeString(str))
        printf("%s is a palindrome string.\n", str);
    else
        printf("%s is not a palindrome string.\n", str);

    return 0;
}

