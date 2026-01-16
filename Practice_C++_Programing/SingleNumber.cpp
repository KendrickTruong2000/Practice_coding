#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = singleNumber(nums);

    cout << result << endl;

    return 0;
}

int singleNumber(vector<int> &nums)
{
    // vector<int> duplicate;
    // int single = 0;

    // if (nums.size() == 1)
    // {
    //     return nums[0];
    // }

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (count(nums.begin(), nums.end(), nums[i]) == 1)
    //     {
    //         single = nums[i];
    //         break;
    //     }
    // }

    // return single;

    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        index = index ^ nums[i];
    }
    return index;
}