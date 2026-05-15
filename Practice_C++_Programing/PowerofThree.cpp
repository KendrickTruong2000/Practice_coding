#include <iostream>

using namespace std;

bool isPowerOfThree(int n);

int main(int argc, char const *argv[])
{
    int n = 0;
    bool isPowOfThree = false;
    cout << "Enter a number: ";
    cin >> n;

    isPowOfThree = isPowerOfThree(n);

    if (isPowOfThree)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}

bool isPowerOfThree(int n)
{
    if (n <= 0)
    {
        return false;
    }

    while (n % 3 == 0)
    {
        n /= 3;
    }
    return n == 1;
}