#include <stdio.h>
int main()
{
    int arr_size, i, pos, newel;
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

    printf("Enter insert position: ");
    scanf("%d", &pos);

    printf("Enter new element: ");
    scanf("%d", &newel);

    for (i = arr_size; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = newel;

    printf("After insertion array = \n");
    for (i = 0; i <= arr_size; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}