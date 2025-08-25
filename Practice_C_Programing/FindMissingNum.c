#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMissing(int arr[], int size);
void printArray(int arr[], int size);

int main(int argc, char const *argv[])
{
    int range, count = 0, i = 0, missingNum = 0;
    printf("Please enter max range: ");
    scanf("%d", &range);

    int arr[range];

    srand(time(NULL));
    int randNum = rand() % range + 1;

    while (count <= range)
    {
        if (count == randNum)
        {
            count++;
            continue;
        }
        else
        {
            arr[i] = count;
            i++;
            count++;
        }
    }

    printf("Array is: ");
    printArray(arr, range);
    missingNum = findMissing(arr, range);
    if (missingNum != 0)
    {
        printf("The number missing in this arry is: %d\n", missingNum);
    }
    else
    {
        printf("The array not missing any number\n");
    }

    return 0;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findMissing(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (count == arr[i])
        {
            count++;
        }
        else
        {
            return count;
        }
    }

    return 0;
}
