#include <iostream>

using namespace std;

bool isPerfectSquare(int);

int main(int argc, char const *argv[])
{
    int num = 16;
    bool isPerSqrt = false;

    isPerSqrt = isPerfectSquare(num);

    if (isPerSqrt)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

bool isPerfectSquare(int num)
{
    if (num < 0)
    {
        return false;
    }

    long long left = 0;
    long long right = num;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == num)
        {
            return true;
        }
        else if (square < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}