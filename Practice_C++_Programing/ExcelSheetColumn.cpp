#include <iostream>
#include <string>

using namespace std;

string converToTitle(int columnNumber);
int titleToNumber(string columnTitle);

int main(int argc, char const *argv[])
{
    // char c;
    // c = 1 + '@';
    // cout << c;
    int nums = 701;
    string result = converToTitle(nums);
    cout << result << endl;
    int numColumn = titleToNumber(result);
    cout << numColumn << endl;

    return 0;
}

string converToTitle(int columnNumber)
{
    string result;
    // char c;

    // if (columnNumber <= 26)
    // {
    //     c = columnNumber + '@';
    // }
    // else
    // {
    //     c = columnNumber / 26 + '@';
    //     result.push_back(c);
    //     c = columnNumber - 26 + '@';
    // }

    // result.push_back(c);

    while (columnNumber > 0)
    {
        columnNumber--;
        int remainder = columnNumber % 26;

        char c = 'A' + remainder;
        result = c + result;

        columnNumber /= 26;
    }

    return result;
}

int titleToNumber(string columnTitle)
{
    // strcpy(arrChar, columnTitle.c_str());
    int result = 0;

    for (char c : columnTitle)
    {
        int value = c - 'A' + 1;
        result = result * 26 + value;
    }

    return result;
}