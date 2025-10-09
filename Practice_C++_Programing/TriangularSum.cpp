// Step-by-step
// check length of vector if length == 1 stop; otherwise plus 2 next numbers to each other
// and store sum to a new vector and put it into the same function.
#include <iostream>
#include <vector>

using namespace std;

int triangularSum(vector<int> &);

int main(int argc, char const *argv[])
{
    int sumOfTriangular = 0;
    vector<int> nums = {1, 2, 3, 4, 5};
    sumOfTriangular = triangularSum(nums);
    cout << sumOfTriangular << "\n";

    return 0;
}

int triangularSum(vector<int> &nums)
{
    vector<int> newNums;
    int sum = 0;
    int row = 0;

    if (nums.size() == 1)
    {
        return nums[0];
    }
    else
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            sum = nums[i] + nums[i + 1];
            if (sum >= 1 && sum <= 9)
            {
                newNums.push_back(sum);
            }
            else
            {
                sum = sum % 10;
                newNums.push_back(sum);
            }
        }
        return triangularSum(newNums);
    }
}
