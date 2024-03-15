#include <stdio.h>

void generateFibonacci(int limit) {
    int first = 0, second = 1, next;

    printf("Fibonacci Series up to %d: %d, %d, ", limit, first, second);

    next = first + second;
    while (next <= limit) {
        printf("%d, ", next);
        first = second;
        second = next;
        next = first + second;
    }
    printf("\n");
}

int main() {
    int limit;

    printf("Enter the limit for Fibonacci series: ");
    scanf("%d", &limit);

    generateFibonacci(limit);

    return 0;
}
