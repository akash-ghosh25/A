#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum = 0;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i]; // Calculate the sum of all elements
    }

    printf("Sum of all elements: %d\n", sum);

    // Free the allocated memory
    free(arr);

    return 0;
}