#include <stdio.h>
#include <stdlib.h>

void rotateArray(int arr[], int size, int k);
void printArray(int arr[], int size);

int main(int argc, char const *argv[])
{
    int size, k;
    printf("Please enter size of the array: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter value for element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Please enter step for rotating: ");
    scanf("%d", &k);

    printf("Array before rotating\n");
    printArray(arr, size);
    printf("Array after rotating at %d:\n", k);
    rotateArray(arr, size, k);
    printArray(arr, size);
    return 0;
}

void rotateArray(int arr[], int size, int k)
{
    int tempArr[k];

    for (int i = 0; i < size; i++)
    {
        if (i <= k)
        {
            tempArr[i] = arr[i];
            arr[i] = arr[i + k + 1];
        }
        else
        {
            arr[i] = tempArr[i - k];
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}