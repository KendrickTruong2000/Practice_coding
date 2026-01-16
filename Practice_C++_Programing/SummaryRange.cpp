#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRange(vector<int> &);

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> result = summaryRange(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

vector<string> summaryRange(vector<int> &nums)
{
    vector<string> result;

    for (int i = 0; i < nums.size(); i++)
    {
        int start = nums[i];
        while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1])
        {
            i++;
        }

        int end = nums[i];

        if (start == end)
        {
            result.push_back(to_string(start));
        }
        else
        {
            result.push_back(to_string(start) + "->" + to_string(end));
        }
    }

    return result;
}