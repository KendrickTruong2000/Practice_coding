#include <iostream>

using namespace std;

bool isPalindormNumber(int);

int main(int argc, char const *argv[])
{
    int num;
    cout << "Please enter a number: ";
    cin >> num;

    if (isPalindormNumber(num))
    {
        cout << "The number is Palindorm" << "\n";
    }
    else
    {
        cout << "The number is not Palindorm" << "\n";
    }

    return 0;
}

bool isPalindormNumber(int num)
{
    bool isPalindorm = false;
    long long tempNum = 0, unit = 0, originNum = 0;

    originNum = num;

    while (originNum != 0)
    {
        unit = originNum % 10;
        tempNum = tempNum * 10 + unit;
        originNum = originNum / 10;
    }

    if (tempNum == num)
    {
        isPalindorm = true;
    }
    else
    {
        isPalindorm = false;
    }

    return isPalindorm;
}
