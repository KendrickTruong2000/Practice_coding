#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> &nums);
bool containsNearlyDuplicate(vector<int> &nums, int k);

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    int k = 2;
    bool result = containsNearlyDuplicate(nums, k);

    if (result)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

bool containsDuplicate(vector<int> &nums)
{
    // bool isDuplicate = false;
    // int count = 0, duplicate = nums[0];

    // sort(nums.begin(), nums.end());

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         if (nums[i] == nums[j])
    //         {
    //             count++;
    //         }
    //     }

    //     if (count == 1)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         i += count;
    //         count = 0;
    //     }
    // }

    // return false;

    unordered_set<int> seen;
    for (int num : nums)
    {
        if (seen.find(num) != seen.end())
        {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

bool containsNearlyDuplicate(vector<int> &nums, int k)
{
    // For small vector size
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         if (nums[i] == nums[j])
    //         {
    //             if (abs(i - j) <= k)
    //             {
    //                 return true;
    //             }
    //         }
    //     }
    // }

    // return false;

    unordered_set<int> window;

    for (int i = 0; i < nums.size(); i++)
    {
        if (window.find(nums[i]) != window.end())
        {
            return true;
        }

        window.insert(nums[i]);

        if (window.size() > k)
        {
            window.erase(nums[i-k]);
        }
    }
    
    return false;
}