#include <iostream>

using namespace std;

bool isValidTriangle(int, int, int);
void checkValidTriangle(int[], int);

int main(int argc, char const *argv[])
{
    int nums[] = {4, 2, 3, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    checkValidTriangle(nums, size);

    return 0;
}

bool isValidTriangle(int a, int b, int c)
{
    if ((a + b > c) && (b + c > a) && (a + c > b))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void checkValidTriangle(int nums[], int size)
{
    int count = 0;
    bool isValid = false;

    for (int i = 0; i < size; i++)
    {
        if (i + 2 < size)
        {
            isValid = isValidTriangle(nums[i], nums[i + 1], nums[i + 2]);
        }
        else
        {
            isValid = isValidTriangle(nums[0], nums[i], nums[(i + 1) % size]);
        }

        if (isValid)
        {
            count++;
        }
    }
    cout << "There are: " << count << "\n";
}