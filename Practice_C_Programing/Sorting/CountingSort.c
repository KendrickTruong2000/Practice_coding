#include <stdio.h>
#include <stdlib.h>

void CountingSort(int arr[], int size);
int FindMax(int arr[], int size);
void PrintArray(int arr[], int size);

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    CountingSort(arr, size);
    PrintArray(arr, size);

    return 0;
}

void CountingSort(int arr[], int size)
{
    int max = FindMax(arr, size);
    // int countArr[max + 1];
    // int outputArr[size];

    // for (int i = 0; i < size; i++)
    // {
    //     countArr[arr[i]]++;
    // }

    // for (int i = 1; i <= max; i++)
    // {
    //     countArr[i] += countArr[i - 1];
    // }

    // for (int i = size - 1; i >= 0; i--)
    // {
    //     outputArr[countArr[arr[i]] - 1] = arr[i];
    //     countArr[arr[i]]--;
    // }

    int *countArr = (int *)calloc(max + 1, sizeof(int));
    int *outputArr = (int *)malloc(size * sizeof(int));
    if (countArr == NULL || outputArr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        countArr[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        countArr[i] += countArr[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        outputArr[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = outputArr[i];
    }
    
    free(countArr);
    free(outputArr);
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
void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
