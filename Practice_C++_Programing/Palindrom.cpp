#include <iostream>

using namespace std;

bool PalindromCheck(string str);

int main(int argc, char const *argv[])
{
    string inputStr;
    bool isPalindrom = true;

    cout << "Please enter a string: ";
    cin >> inputStr;

    isPalindrom = PalindromCheck(inputStr);

    if (isPalindrom == true)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}

bool PalindromCheck(string str)
{
    bool isPalindrom;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != str[str.length() - i - 1])
        {
            isPalindrom = false;
            break;
        }

        isPalindrom = true;
    }

    return isPalindrom;
}
