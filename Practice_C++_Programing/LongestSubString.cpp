#include <iostream>
#include <string.h>

using namespace std;

int findLongestSubString(string);

int main(int argc, char const *argv[])
{
    string str;

    cout << "Please enter a string: ";
    cin >> str;

    findLongestSubString(str);
    return 0;
}

int findLongestSubString(string str)
{
    int maxLen = 0;
    string tempStr;

    for (int i = 0; i < str.length(); i++)
    {
        if (tempStr.find(str[i]) == string::npos)
        {
            tempStr += str[i];
            if (tempStr.length() > maxLen)
                maxLen = tempStr.length();
        }
        else
        {
            // Remove characters up to and including the first occurrence of str[i]
            tempStr = tempStr.substr(tempStr.find(str[i]) + 1);
            tempStr += str[i];
        }
    }

    cout << maxLen;

    return maxLen;
}
