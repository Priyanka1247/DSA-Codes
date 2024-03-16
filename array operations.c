#include <stdio.h>


int findLargest(int arr[], int size) {
    int largest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}


int findSmallest(int arr[], int size) {
    int smallest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    return smallest;
}


int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}


float calculateAverage(int arr[], int size) {
    int sum = calculateSum(arr, size);
    return (float)sum / size;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Largest element: %d\n", findLargest(arr, size));
    printf("Smallest element: %d\n", findSmallest(arr, size));
    printf("Sum of elements: %d\n", calculateSum(arr, size));
    printf("Average of elements: %.2f\n", calculateAverage(arr, size));

    return 0;
}
