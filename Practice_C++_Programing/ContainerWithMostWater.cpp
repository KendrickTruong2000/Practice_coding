#include <iostream>

using namespace std;

int maxArea(int[], int);
int FindMax(int[], int, int, int *);

int main(int argc, char const *argv[])
{
    int size = 0, result = 0;

    cout << "Please enter size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Please enter value for each elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i << " ";
        cin >> arr[i];
    }

    result = maxArea(arr, size);

    cout << "The maximum area of water is: " << result;

    return 0;
}

int maxArea(int arr[], int size)
{
    int areaMax = 0, tempArea = 0;
    int width = 0, height = 0, j = size - 1, i = 0;

    while (j != i)
    {
        width = j - i;

        if (arr[i] > arr[j])
        {
            height = arr[j];
            j--;
        }
        else if (arr[i] <= arr[j])
        {
            height = arr[i];
            i++;
        }
        // cout << height << " " << width << "\n";
        tempArea = height * width;

        if (tempArea > areaMax)
        {
            areaMax = tempArea;
        }
    }

    return areaMax;
}
