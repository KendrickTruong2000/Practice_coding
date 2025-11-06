#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &);

int main(int argc, char const *argv[])
{
    int result = 0;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    result = removeDuplicates(nums);
    cout << result << endl;
    return 0;
}

int removeDuplicates(vector<int> &nums)
{
    vector<int> nonDuplicates;

    for (int i = 0; i < nums.size(); i++)
    {

        auto isExist = find(nonDuplicates.begin(), nonDuplicates.end(), nums[i]);

        // Found
        if (isExist != nonDuplicates.end())
        {
            continue;
        }
        // Not found
        else
        {
            nonDuplicates.push_back(nums[i]);
            nums.push_back(nums[i]);
        }
    }

    for (int j = 0; j < nonDuplicates.size(); j++)
    {
        nums[j] = nonDuplicates[j];
        cout << nonDuplicates[j] << " ";
    }
    cout << endl;
    return nonDuplicates.size();
}