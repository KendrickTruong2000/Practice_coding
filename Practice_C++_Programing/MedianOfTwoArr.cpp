#include <iostream>
#include <vector>

using namespace std;

vector<int> mergArray(vector<int> &, vector<int> &, int, int);
double findMedian(vector<int> &, vector<int> &);

int main(int argc, char const *argv[])
{
    double median = 0;
    vector<int> num1 = {1, 2};
    vector<int> num2 = {3, 4};

    median = findMedian(num1, num2);

    cout << "Median is: " << median << "\n";

    return 0;
}

vector<int> mergArray(vector<int> &num1, vector<int> &num2, int m, int n)
{
    vector<int> mergeArr;
    int i = 0, j = 0, k = 0;

    // Merge the two arrays
    while (i < m && j < n)
    {
        if (num1[i] < num2[j])
            mergeArr.push_back(num1[i++]);
        else
            mergeArr.push_back(num2[j++]);
    }

    // Copy remaining elements of num1
    while (i < m)
        mergeArr.push_back(num1[i++]);

    // Copy remaining elements of num2
    while (j < n)
        mergeArr.push_back(num2[j++]);

    return mergeArr;
}

double findMedian(vector<int> &num1, vector<int> &num2)
{
    int size, size1, size2;
    double median = 0;
    size1 = num1.size();
    size2 = num2.size();
    vector<int> mergedSortedArray = mergArray(num1, num2, size1, size2);
    size = mergedSortedArray.size();
    if (size % 2 == 0)
    {
        median = (mergedSortedArray[size / 2] + mergedSortedArray[size / 2 - 1]) / 2.0;
    }
    else
    {
        median = mergedSortedArray[size / 2];
    }

    return median;
}