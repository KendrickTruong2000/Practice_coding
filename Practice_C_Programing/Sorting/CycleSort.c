#include <stdio.h>
#include <stdlib.h>

void CycleSort(int arr[], int size);
void PrintArray(int arr[], int size);
void Swap(int *a, int *b);

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

    CycleSort(arr, size);
    PrintArray(arr, size);
    return 0;
}
void CycleSort(int arr[], int size)
{
    int writes = 0;

    for (int cycle_start = 0; cycle_start <= size - 2; cycle_start++)
    {
        int item = arr[cycle_start];
        int pos = cycle_start;

        for (int i = cycle_start + 1; i < size; i++)
        {
            if (arr[i] < item)
            {
                pos++;
            }
        }

        if (pos == cycle_start)
        {
            continue;
        }

        while (item == arr[pos])
        {
            pos++;
        }

        if (pos != cycle_start)
        {
            Swap(&item, &arr[pos]);
            writes++;
        }

        while (pos != cycle_start)
        {
            pos = cycle_start;

            for (int i = cycle_start + 1; i < size; i++)
            {
                if (arr[i] < item)
                {
                    pos++;
                }
            }

            while (item == arr[pos])
            {
                pos++;
            }

            if (item != arr[pos])
            {
                Swap(&item, &arr[pos]);
                writes++;
            }
        }
    }

    printf("Number of writes: %d\n", writes);
}
void PrintArray(int arr[], int size)
{
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}