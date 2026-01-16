#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,3};
    int result = majorityElement(nums);

    cout << result << endl;

    return 0;
}

int majorityElement(vector<int> &nums)
{
    // int indexMid = 0;

    // sort(nums.begin(), nums.end());

    // indexMid = nums.size() / 2;

    // return nums[indexMid];

    int candidate = 0, count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (candidate == 0)
        {
            candidate = nums[i];
            count = 1;
        }
        else if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    
    return candidate;
}