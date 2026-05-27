#include <iostream>

using namespace std;

bool isPowerOfFour(int);

int main(int argc, char const *argv[])
{
    int n = 0;
    bool isPowerFour = false;

    cout << "Please enter a number: ";
    cin >> n;

    isPowerFour = isPowerOfFour(n);

    if (isPowerFour)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
bool isPowerOfFour(int n)
{
    if (n <= 0)
    {
        return false;
    }

    while (n % 4 == 0)
    {
        n /= 4;
    }
    return n == 1;
}