#include <iostream>

using namespace std;

int *twoSum(int[], int, int);

int main(int argc, char const *argv[])
{
    int num[4] = {2, 7, 11, 14};
    int target = 9;
    int *sumArray = twoSum(num, target, 4);

    cout << "Index of two sum are: " << sumArray[0] << " " << sumArray[1] << "\n";

    return 0;
}

int *twoSum(int nums[], int target, int size)
{
    int *arrSum = new int[2]{0, 0};
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            sum = nums[i] + nums[j];

            if (sum == target)
            {
                arrSum[0] = i;
                arrSum[1] = j;
                return arrSum;
            }
        }
    }

    return arrSum;
}