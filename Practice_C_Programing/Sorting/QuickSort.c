#include <stdio.h>
#include <stdlib.h>

void QuickSort(int arr[], int low, int high);
void PrintArray(int arr[], int size);
void Swap(int *a, int *b);
int Partition(int arr[], int low, int high);

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

    // Time Complexity:
    // Best Case: O(n log n)
    // Average Case: O(n log n)
    // Worst Case: O(n^2)
    // Space Complexity: O(log n)
    QuickSort(arr, 0, size - 1);
    PrintArray(arr, size);

    return 0;
}
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }

    Swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void QuickSort(int arr[], int low, int high)
{
    int pi = 0;

    if (low < high)
    {
        pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
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
