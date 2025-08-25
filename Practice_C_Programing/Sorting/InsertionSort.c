#include <stdio.h>

void InsertionSort(int arr[], int size);
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
    // Best Case: O(n)
    // Average Case: O(n^2)
    // Worst Case: O(n^2)
    // Space Complexity: O(1)
    InsertionSort(arr, size);
    PrintArray(arr, size);
    return 0;
}

void InsertionSort(int arr[], int size)
{
    int key, temp = 0;

    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        temp = i - 1;

        while (temp >= 0 && arr[temp] > key)
        {
            arr[temp + 1] = arr[temp];
            temp--;
        }
        arr[temp + 1] = key;
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