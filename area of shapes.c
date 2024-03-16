#include <stdio.h>
#include <math.h>

#define PI 3.14159


float areaRectangle(float length, float width) {
    return length * width;
}


float areaTriangle(float base, float height) {
    return 0.5 * base * height;
}


float areaCircle(float radius) {
    return PI * radius * radius;
}

int main() {
    int choice;
    float length, width, base, height, radius;

    printf("Choose the shape to calculate its area:\n");
    printf("1. Rectangle\n");
    printf("2. Triangle\n");
    printf("3. Circle\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the length and width of the rectangle: ");
            scanf("%f %f", &length, &width);
            printf("Area of the rectangle: %.2f\n", areaRectangle(length, width));
            break;
        case 2:
            printf("Enter the base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            printf("Area of the triangle: %.2f\n", areaTriangle(base, height));
            break;
        case 3:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            printf("Area of the circle: %.2f\n", areaCircle(radius));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
