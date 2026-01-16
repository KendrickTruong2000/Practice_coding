#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int threeSumClosest(vector<int> &nums, int target);

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 3, 4, 7, 8, 9};
    int target = 15;

    int result = threeSumClosest(nums, target);

    cout << result << endl;

    return 0;
}

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int dis1 = 0, dis2 = 0;
    int closest = nums[0] + nums[1] + nums[2];

    if (n < 3)
    {
        return 0;
    }

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(closest - target))
            {
                closest = sum;
            }
            if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return closest;
}
