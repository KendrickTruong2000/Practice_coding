#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &, int);

int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 3, 3};
    int val = 2, result = 0;
    result = removeElement(nums, val);

    cout << result << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

int removeElement(vector<int> &nums, int val)
{
    int temp = 0, k = 0;

    for (int i = 0; i < nums.size();)
    {
        if (val == nums[i])
        {
            nums.erase(nums.begin() + i);
        }
        else
        {
            i++;
        }
    }

    return nums.size();
}
