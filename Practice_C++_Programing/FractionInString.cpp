#include <iostream>
#include <string>

using namespace std;

string fractionToDecimal(int, int);
string intToString(int);

int main(int argc, char const *argv[])
{
    int numerator, denominator;
    string result;
    cout << "Please enter numerator: ";
    cin >> numerator;
    cout << "Please enter denominator: ";
    cin >> denominator;
    result = fractionToDecimal(numerator, denominator);
    cout << result << "\n";

    return 0;
}

string intToString(int num)
{
    bool isNagative = false;
    string stringNum = " ";

    if (num == 0)
    {
        return "0";
    }

    if (num < 0)
    {
        isNagative = true;
        num = -num;
    }

    while (num > 0)
    {
        stringNum = char('0' + (num % 10)) + stringNum;
        num /= 10;
    }
    
    if (isNagative)
    {
        stringNum = "-" + stringNum;
    }
    
    return stringNum;
}

string fractionToDecimal(int numerator, int denominator)
{
    string result = "";
    long n, d, rem;

    if ((numerator < 0) ^ (denominator < 0) && denominator != 0)
    {
        result += "-";
    }

    n = abs((long)numerator);
    d = abs((long)denominator);

    result += intToString(n / d);

    rem = n % d;
    if (rem == 0)
    {
        return result;
    }
    
    result += ".";

    for (int i = 0; i < 10 && rem != 0; i++)
    {
        rem *= 10;
        result += char('0' + (rem / d));
        rem %= d;
    }

    return result;
}
