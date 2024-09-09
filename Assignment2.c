#include <stdio.h>
int main()
{
    int arr_size, i, pos;
    int arr[100];
    printf("Enter array size: ");
    scanf("%d", &arr_size);

    for (i = 0; i < arr_size; i++)
    {
        printf("Enter %dth Element: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Array =\n");
    for (i = 0; i < arr_size; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");

    printf("Enter deleting position: ");
    scanf("%d", &pos);

    for (i = pos; i < arr_size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    printf("After deleting array element= \n");
    for (i = 0; i < arr_size - 1; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}