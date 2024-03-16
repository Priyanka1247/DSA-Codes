#include <stdio.h>

#define MAX_SIZE 10


void addMatrix(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}


void subtractMatrix(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}


void multiplyMatrix(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


void transposeMatrix(int A[][MAX_SIZE], int rows, int cols) {
    int temp[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[j][i] = A[i][j];
        }
    }

    printf("Transpose of the matrix:\n");
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
}


void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;


    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            scanf("%d", &A[i][j]);
        }
    }


    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            scanf("%d", &B[i][j]);
        }
    }


    if (rows1 == rows2 && cols1 == cols2) {
        printf("Matrix addition:\n");
        addMatrix(A, B, C, rows1, cols1);
        displayMatrix(C, rows1, cols1);
    } else {
        printf("Matrices cannot be added due to mismatched dimensions.\n");
    }


    if (rows1 == rows2 && cols1 == cols2) {
        printf("Matrix subtraction:\n");
        subtractMatrix(A, B, C, rows1, cols1);
        displayMatrix(C, rows1, cols1);
    } else {
        printf("Matrices cannot be subtracted due to mismatched dimensions.\n");
    }


    if (cols1 == rows2) {
        printf("Matrix multiplication:\n");
        multiplyMatrix(A, B, C, rows1, cols1, cols2);
        displayMatrix(C, rows1, cols2);
    } else {
        printf("Matrices cannot be multiplied due to mismatched dimensions.\n");
    }


    printf("Transpose of matrix A:\n");
    transposeMatrix(A, rows1, cols1);

    return 0;
}
