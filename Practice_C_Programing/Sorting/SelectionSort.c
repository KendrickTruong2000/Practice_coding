#include <stdio.h>

void SelectionSort(int arr[], int size);

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
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    SelectionSort(arr, size);

    return 0;
}

void SelectionSort(int arr[], int size)
{
    int min = 0, temp = 0;

    for (int i = 0; i < size; i++)
    {
        min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}