#include <stdio.h>
// min and max of array

int main()
{
    int size;
    int i, min, max;

    printf("Enter a size of array : "); // size from user
    scanf("%d", &size);

    //	int *a = (int*)malloc(size * sizeof(int));
    int *a = new int[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter elements in array : \n"); // elements from user
        scanf("%d", &a[i]);
    }
    min = max = a[0];

    for (i = 1; i < size; i++)
    {

        if (min > a[i])
            min = a[i];

        if (max < a[i])
            max = a[i];
    }
    delete[] a;

    printf("min of array is %d\n", min);
    printf("max of array is %d\n", max);

    return 0;
}