#include <iostream>

using namespace std;

bool isPowerOfTwo(int n);

int main(int argc, char const *argv[])
{
    int n = 0;
    bool result = isPowerOfTwo(n);

    if (result)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

bool isPowerOfTwo(int n)
{
    long int power = 1, i = 0;
    if (n == 1)
    {
        return true;
    }

    while (power != n)
    {
        power = pow(2, i);

        if (power > n)
        {
            return false;
        }

        i++;
    }

    return true;
}