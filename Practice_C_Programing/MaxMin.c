#include <stdio.h>

int FindMax(int arr[], int size);
int FindMin(int arr[], int size);

int main(int argc, char const *argv[])
{
    int arr[5];
    int max, min;

    printf("Enter 5 integers: ");

    for (int i = 0; i < 5; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    max = FindMax(arr, 5);
    min = FindMin(arr, 5);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}

int FindMax(int arr[], int size)
{
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}

int FindMin(int arr[], int size)
{
    int min = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    return min;
}