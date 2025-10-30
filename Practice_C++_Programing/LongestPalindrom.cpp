#include <iostream>
#include <string>

using namespace std;

bool checkPalindrom(string);
string longestPalindrom(string);
string copyString(string, int, int);

int main(int argc, char const *argv[])
{
    string str;
    cout << "Please eneter a string: ";
    cin >> str;

    cout << "Longest palindrome: " << longestPalindrom(str) << endl;

    return 0;
}

string longestPalindrom(string str)
{
    bool isPalindrom = false;
    int k = str.length();
    int max_len = 0;
    string tempSub = " ", palindromStr = " ";

    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < k; j++)
        {
            tempSub = copyString(str, i, j + 1);
            if (checkPalindrom(tempSub) && tempSub.length() > max_len)
            {
                max_len = tempSub.length();
                palindromStr = tempSub;
            }
        }
    }

    return palindromStr;
}

string copyString(string src, int from, int to)
{
    string dst = "";
    for (int i = from; i < to; i++)
    {
        dst += src[i];
    }
    return dst;
}
bool checkPalindrom(string str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - 1 - i])
        {
            return false;
        }
    }
    return true;
}