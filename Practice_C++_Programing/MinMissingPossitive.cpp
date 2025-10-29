#include <iostream>
#include <vector>

using namespace std;

int findSmallestInteger(vector<int> &, int);

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 4, -1 ,1};
    int value = 0, result = 0;

    cout << "Please enter a value: ";
    cin >> value;
    result = findSmallestInteger(nums, value);
    cout << result << "\n";
    return 0;
}

int findSmallestInteger(vector<int> &nums, int value)
{
    int temp = 0, missingMin = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 1 && nums[i] < value)
        {
            temp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[nums[i] - 1] = temp;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    

    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] + 1 != nums[j + 1])
        {
            missingMin = nums[j] + 1;
        }
        
    }
    
    return missingMin;
}
