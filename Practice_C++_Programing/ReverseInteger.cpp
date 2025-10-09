#include <iostream>

using namespace std;

int reverseInt(int);

int main(int argc, char const *argv[])
{
    int num, result;

    cout << "Please eneter a number: ";
    cin >> num;

    result = reverseInt(num);
    cout << "Number after revers is: " << result << "\n";
    return 0;
}

int reverseInt(int num)
{
    int tempNum = 0;
    long long result = 0;

    while (num != 0)
    {
        tempNum = num % 10;
        result = result * 10 + tempNum;
        num = num / 10;
    }

    if (result > INT32_MAX || result < INT32_MIN)
    {
        return 0;
    }

    return (int)result;
}