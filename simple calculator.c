#include <stdio.h>


float add(float num1, float num2) {
    return num1 + num2;
}


float subtract(float num1, float num2) {
    return num1 - num2;
}


float multiply(float num1, float num2) {
    return num1 * num2;
}


float divide(float num1, float num2) {
    if (num2 != 0)
        return num1 / num2;
    else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

int main() {
    int choice;
    float num1, num2;

    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch (choice) {
        case 1:
            printf("Result: %.2f\n", add(num1, num2));
            break;
        case 2:
            printf("Result: %.2f\n", subtract(num1, num2));
            break;
        case 3:
            printf("Result: %.2f\n", multiply(num1, num2));
            break;
        case 4:
            printf("Result: %.2f\n", divide(num1, num2));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
