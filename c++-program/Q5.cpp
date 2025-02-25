//he code below is intended to multiply two matrices AAA and BBB and store the result in matrix CCC. However, the code contains bugs in the dynamic memory allocation loops and indexing, which cause incorrect results and may lead to runtime errors.
//Buggy Code:
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1 = 2, c1 = 3;
    int r2 = 3, c2 = 2;
    
    // Check if matrices can be multiplied
    if(c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }
    
    // Allocate memory for matrices A, B, and C
    int **A = (int **)malloc(r1 * sizeof(int *));
    int **B = (int **)malloc(r2 * sizeof(int *));
    int **C = (int **)malloc(r1 * sizeof(int *));
    
    for (int i = 0; i <= r1; i++) {  // Bug: should use i < r1 instead of i <= r1
        A[i] = (int *)malloc(c1 * sizeof(int));
        C[i] = (int *)malloc(c2 * sizeof(int));
    }
    for (int i = 0; i <= r2; i++) {  // Bug: should use i < r2 instead of i <= r2
        B[i] = (int *)malloc(c2 * sizeof(int));
    }
    
    // Initialize matrix A
    int count = 1;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            A[i][j] = count++;
        }
    }
    
    // Initialize matrix B
    count = 1;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            B[i][j] = count++;
        }
    }
    
    // Multiply A and B, store result in C
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {  // c1 and r2 are equal; using c1 here is fine.
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    // Print matrix C
    printf("Result matrix C:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    // Free allocated memory
    for (int i = 0; i < r1; i++) {
        free(A[i]);
        free(C[i]);
    }
    for (int i = 0; i < r2; i++) {
        free(B[i]);
    }
    free(A);
    free(B);
    free(C);
    
    return 0;
}

/*Expected Output:
//Given matrix AAA as:

1 2 3
4 5 6

and matrix BBB as:

1 2
3 4
5 6

The product matrix CCC should be:

22 28
49 64*/
