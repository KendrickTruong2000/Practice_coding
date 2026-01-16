#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {0, 0, 0};
    vector<vector<int>> result = threeSum(nums);

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

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1])
                {
                    ++left;
                }

                while (left < right && nums[right] == nums[right - 1])
                {
                    --right;
                }

                ++left;
                --right;
            }
            else if (sum < 0)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
    }

    return result;
}

// limited to the small and midium array size
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     int length = nums.size();
//     vector<vector<int>> result;
//     set<vector<int>> uniqueTriplets;

//     for (int i = 0; i < length; i++)
//     {
//         for (int j = i + 1; j < length; j++)
//         {
//             for (int k = j + 1; k < length; k++)
//             {
//                 if (nums[i] + nums[j] + nums[k] == 0)
//                 {
//                     vector<int> triplet = {nums[i], nums[j], nums[k]};
//                     sort(triplet.begin(), triplet.end());
//                     if (uniqueTriplets.find(triplet) == uniqueTriplets.end())
//                     {
//                         uniqueTriplets.insert(triplet);
//                         result.push_back(triplet);
//                     }
//                 }
//             }
//         }
//     }

//     return result;
// }
