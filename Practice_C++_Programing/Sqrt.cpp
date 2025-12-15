#include <iostream>

using namespace std;

int mySqrt(int);

int main(int argc, char const *argv[])
{
    long int num = 2147395600;
    int result = 0;
    result = mySqrt(num);
    cout << result << endl;
    return 0;
}

int mySqrt(int x)
{
    long int result = 1;

    while (result * result <= x)
    {
        result++;
    }

    return result - 1;
}