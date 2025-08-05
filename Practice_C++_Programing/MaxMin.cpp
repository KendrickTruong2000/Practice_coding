#include <iostream>

using namespace std;

int FindMax(int[], int);
int FindMin(int[], int);

int main(int argc, char const *argv[])
{
    int arr[5] = {10, 3, 5, 22, 7};
    int max = 0, min = 0;

    max = FindMax(arr, 5);
    min = FindMin(arr, 5);

    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;

    return 0;
}

int FindMax(int arr[], int length)
{
    int temp = arr[0], max = 0;

    for (int i = 1; i < 5; i++)
    {
        if (temp < arr[i])
        {
            temp = arr[i];
        }
    }

    max = temp;

    return max;
}

int FindMin(int arr[], int length)
{
    int temp = arr[0], min = 0;

    for (int i = 1; i < length; i++)
    {
        if (temp > arr[i])
        {
            temp = arr[i];
        }
    }

    min = temp;

    return min;
}