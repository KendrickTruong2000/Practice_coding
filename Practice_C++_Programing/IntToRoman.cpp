#include <iostream>
#include <string>

using namespace std;

string convertIntToRoman(int);

int main(int argc, char const *argv[])
{
    int num = 0;
    string romanNum;

    cout << "Please enter a number to convert to Roman number: ";
    cin >> num;

    romanNum = convertIntToRoman(num);

    cout << num << " to Roman: " << romanNum;
    return 0;
}

string convertIntToRoman(int num)
{
    string RomanNumArr[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int basicRoman[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string result = "";

    for (int i = 0; i < 13 && num > 0; i++)
    {
        while (num >= basicRoman[i])
        {
            num -= basicRoman[i];
            result += RomanNumArr[i];
        }
    }

    return result;
}
