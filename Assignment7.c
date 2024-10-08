#include <stdio.h>

int main()
{
    int a[10][10], transpose[10][10];
    int r, c;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    // Input: Read matrix elements
    printf("\nEnter matrix elements:\n");
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    // Display the original matrix
    printf("\nEntered matrix:\n");
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            printf("%d  ", a[i][j]);
            if (j == c - 1)
                printf("\n");
        }
    }

    // Compute the transpose
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            transpose[j][i] = a[i][j];
        }
    }

    // Display the transpose
    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < c; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            printf("%d  ", transpose[i][j]);
            if (j == r - 1)
                printf("\n");
        }
    }

    return 0;
}
