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

    // MUL the matrices
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the result
    printf("Multiplication of the matrices:\n");
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