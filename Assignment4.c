#include <stdio.h>
int main()
{
    int arr_size, i;
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

    for (i = 0; i < arr_size / 2; i++)
    {
        int t = arr[i];
        arr[i] = arr[arr_size - i - 1];
        arr[arr_size - i - 1] = t;
    }

    printf("After reverse array = \n");
    for (i = 0; i < arr_size; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}