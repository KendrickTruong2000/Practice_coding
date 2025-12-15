#include <iostream>

using namespace std;

int climbStairs(int);

int main(int argc, char const *argv[])
{
    int steps = 3;
    int result = 0;
    result = climbStairs(steps);
    cout << result << endl;
    return 0;
}

int climbStairs(int n)
{
    int prev1 = 2;
    int prev2 = 1;
    int current = 0;

    if (n <= 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }
    
    for (int i = 3; i <= n; i++)
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}
