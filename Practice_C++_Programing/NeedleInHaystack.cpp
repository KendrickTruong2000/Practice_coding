#include <iostream>
#include <string.h>

using namespace std;

int strStr(string, string);

int main(int argc, char const *argv[])
{
    string haystack = "leetcode";
    string needle = "leeto";
    int result = 0;

    result = strStr(haystack, needle);
    cout << result << endl;
    return 0;
}

int strStr(string haystack, string needle)
{
    int index = -1, count = 0;

    for (int i = 0; i < haystack.length(); i++)
    {
        count = i;
        for (int j = 0; j < needle.length(); j++)
        {
            if (needle[j] == haystack[count])
            {
                if (j == needle.length() - 1)
                {
                    return i;
                }
                else
                {
                    count++;
                }
            }
            else
            {
                index = -1;
                break;
            }
        }
    }

    return index;
}