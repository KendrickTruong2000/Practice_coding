#include <iostream>
#include <math.h>

using namespace std;

bool isHappy(int n);
int nextNumber(int n);

int main(int argc, char const *argv[])
{
    int n = 4;
    bool result = isHappy(n);

    if (result == 1)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = nextNumber(n);

    while (fast != 1 && slow != fast)
    {
        slow = nextNumber(slow);
        fast = nextNumber(nextNumber(fast));
    }
    
    return fast == 1;
}

int nextNumber(int n)
{
    int sum = 0;

    while (n > 0)
    {
        int digit = n % 10;
        sum += pow(digit, 2);
        n /= 10;
    }

    return sum;
}