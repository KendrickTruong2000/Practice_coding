#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &, int, int);

int main(int argc, char const *argv[])
{
    vector<int> num = {11, 2, 15, 7};
    int target = 9;
    vector<int> sumArray = twoSum(num, target, 4);

    cout << "Index of two sum are: " << sumArray[0] << " " << sumArray[1] << "\n";

    return 0;
}

vector<int> twoSum(vector<int> &nums, int target, int size)
{
    vector<int> result;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            sum = nums[i] + nums[j];

            if (sum == target)
            {
                result.push_back(i);
                result.push_back(j);
            }
        }
    }

    return result;
}