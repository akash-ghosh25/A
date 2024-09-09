#include<stdio.h>
int main(){
    int arr_size,i,sum = 0;
    int arr[100];
    printf("Enter array size: ");
    scanf("%d",&arr_size);

    for(i = 0; i<arr_size; i++){
        printf("Enter %dth Element: ",i);
        scanf("%d",&arr[i]);
    }

    printf("Array =\n");
    for(i = 0; i<arr_size; i++){
        printf("%d\t",arr[i]);
    }

    printf("\n");

    for(i=0; i<arr_size; i++){
        sum += arr[i];
    }

    printf("Sum of array Elements = %d",sum);

    return 0;
}