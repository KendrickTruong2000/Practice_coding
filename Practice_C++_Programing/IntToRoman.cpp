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
    string RomanNumArr[] = {"M", "D", "C", "L", "X", "I"};
    int basicRoman[] = {1000, 500, 100, 50, 10, 1};
    string result = "";

    for (int i = 0; i < 6 && num > 0; i++)
    {
        while (num >= basicRoman[i])
        {
            num -= basicRoman[i];
            result += RomanNumArr[i];
        }
        
    }

    return result;
}

