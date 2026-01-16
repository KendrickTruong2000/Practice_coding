#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target);

int main(int argc, char const *argv[])
{
    //-2, -1, 0, 0, 1, 2
    vector<int> nums = {2, 1, 0, -1};
    int target = 2;
    vector<vector<int>> result = fourSum(nums, target);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            int left = j + 1, right = n - 1;
            while (left < right)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                    {
                        ++left;
                    }

                    while (left < right && right + 1 < n && nums[right] == nums[right + 1])
                    {
                        --right;
                    }

                    ++left;
                    --right;
                }
                else if (sum < target)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }
    }

    return result;
}
