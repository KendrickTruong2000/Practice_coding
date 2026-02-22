#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveZeros(vector<int> &);

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeros(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

void moveZeros(vector<int> &nums)
{
    vector<int> arrZeros;
    int count = 0;

    bool allZeros = all_of(nums.begin(), nums.end(), [](int i)
                           { return i == 0; });

    if (nums.size() != 1 && allZeros == 0)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                arrZeros.push_back(nums[i]);
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        nums.insert(nums.end(), arrZeros.begin(), arrZeros.end());
    }
}