#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter the size of the matrices (n): ");
    scanf("%d", &n);

    int matrix1[n][n], matrix2[n][n], result[n][n];

    // Input elements for matrix 1
    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements for matrix 2
    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Add the matrices
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the result
    printf("Sum of the matrices:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}