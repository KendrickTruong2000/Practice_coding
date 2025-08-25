#include <stdio.h>
#include <stdlib.h>

void HeapSort(int arr[], int size);
void Heapify(int arr[], int size, int root);
void Swap(int *a, int *b);
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
    // Time Complexity:
    // Best Case: O(n log n)
    // Space Complexity: O(1)
    HeapSort(arr, size);
    PrintArray(arr, size);
    
    return 0;
}

void HeapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, size, i);
    }

    for (int j = size - 1; j > 0; j--)
    {
        Swap(&arr[0], &arr[j]);
        Heapify(arr, j, 0);
    }
}

void Heapify(int arr[], int size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    
    if (largest != root)
    {
        Swap(&arr[root], &arr[largest]);
        Heapify(arr, size, largest);
    }
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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