#include <iostream>

using namespace std;

int *mergArray(int[], int[], int, int);
double findMedian(int *, int);

int main(int argc, char const *argv[])
{
    int m, n;
    int *arrPtr;
    double median;

    cout << "Please enter size for two array: ";
    cin >> m;
    cin >> n;

    int arr1[m];
    int arr2[n];

    cout << "Please enter element for array 1: \n";

    for (int i = 0; i < m; i++)
    {
        cout << "Element " << i << ": ";
        cin >> arr1[i];
    }

    cout << "Please enter element for array 2: \n";

    for (int j = 0; j < n; j++)
    {
        cout << "Element " << j << ": ";
        cin >> arr2[j];
    }

    arrPtr = mergArray(arr1, arr2, m, n);

    for (int i = 0; i < m + n; i++)
    {
        cout << arrPtr[i] << " ";
    }
    cout << "\n";

    median = findMedian(arrPtr, m + n);

    cout << "Median is: " << median << "\n";

    return 0;
}

int *mergArray(int arr1[], int arr2[], int m, int n)
{
    int *mergeArr = new int[m + n];
    int i = 0, j = 0, k = 0;

    // Merge the two arrays
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            mergeArr[k++] = arr1[i++];
        else
            mergeArr[k++] = arr2[j++];
    }

    // Copy remaining elements of arr1
    while (i < m)
        mergeArr[k++] = arr1[i++];

    // Copy remaining elements of arr2
    while (j < n)
        mergeArr[k++] = arr2[j++];

    return mergeArr;
}

double findMedian(int *ptr, int size)
{
    double median = 0;
    if (size % 2 == 0)
    {
        median = (ptr[size / 2] + ptr[size / 2 - 1]) / 2;
    }
    else
    {
        median = ptr[size / 2];
    }

    return median;
}