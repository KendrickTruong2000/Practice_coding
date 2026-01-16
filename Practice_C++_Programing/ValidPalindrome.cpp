#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string removeUniqueSpaceChar(string str);
bool isPalindrome(string s);

int main(int argc, char const *argv[])
{
    string s = "A man, a plan, a canal: Panama";
    bool result = isPalindrome(s);

    if (result == 1)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}

bool isPalindrome(string s)
{
    string str;
    int lastInd = 0;

    for (auto &x : s)
    {
        x = tolower(x);
    }

    str = removeUniqueSpaceChar(s);
    lastInd = str.size() - 1;

    if (str.empty())
    {
        return true;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != str[lastInd - i])
        {
            return false;
        }
    }
    return true;
}

string removeUniqueSpaceChar(string str)
{
    str.erase(remove_if(str.begin(), str.end(), [](unsigned char c)
                        { return !isalnum(c); }),
              str.end());
    return str;
}