#include <iostream>
#include <vector>

using namespace std;

bool isUgly(int);
bool isPrime(int);

int main(int argc, char const *argv[])
{
    int n = 6;
    bool result = isUgly(n);

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

bool isUgly(int n)
{
    if (n <= 0)
    {
        return false;
    }

    for (int factor : {2, 3, 5})
    {
        while (n % factor == 0)
        {
            n /= factor;
        }
    }

    return n == 1;
}

bool isPrime(int num)
{
    if (num < 1)
    {
        return true;
    }

    if (num <= 3)
    {
        return true;
    }

    if (num % 2 == 0 || num % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}