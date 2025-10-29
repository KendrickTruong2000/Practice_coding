#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &);

int main(int argc, char const *argv[])
{
    // vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs = {"aaa", "aa", "aaa"};
    cout << longestCommonPrefix(strs) << "\n";
    return 0;
}

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";

    // Find shortest string length to avoid out of bounds
    int minLen = strs[0].length();
    for (const string &s : strs)
    {
        minLen = min(minLen, (int)s.length());
    }

    // Compare characters position by position
    string result;
    for (int i = 0; i < minLen; i++)
    {
        char current = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[j][i] != current)
            {
                return result;
            }
        }
        result += current;
    }

    return result;
}
