#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int missingNumber(vector<int> &);

int main(int argc, char const *argv[])
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int result = missingNumber(nums);

    cout << result << endl;

    return 0;
}

int missingNumber(vector<int> &nums)
{
    int count = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != count)
        {
            return count;
        }

        count++;
    }

    return count++;
}