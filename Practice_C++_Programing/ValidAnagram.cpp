#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string, string);

int main(int argc, char const *argv[])
{
    string s = "aabbbb";
    string t = "aaaabb";
    bool result = isAnagram(s, t);

    if (result)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    int freq[256] = {0};

    for(char c : s)
    {
        freq[(unsigned char)c]++;
    }

    for(char c : t)
    {
        freq[(unsigned char)c]--;
        if (freq[(unsigned char)c] < 0)
        {
            return false;
        }
    }

    return true;
}