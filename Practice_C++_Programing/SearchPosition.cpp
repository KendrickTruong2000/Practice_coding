#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &, int);
int binarySearch(vector<int> &, int);

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 7, result = 0;

    result = searchInsert(nums, target);
    cout << result << endl;
    return 0;
}

int searchInsert(vector<int> &nums, int target)
{
    int result = 0;

    result = binarySearch(nums, target);

    if (result == -1)
    {
        if (nums[nums.size() - 1] < target)
        {
            return nums.size();
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > target)
                {
                    return i;
                }
            }
        }
    }
    return result;
}

int binarySearch(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
