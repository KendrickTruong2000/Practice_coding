#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool wordPattern(string, string);
void splitString(vector<string> &, string);

int main(int argc, char const *argv[])
{
    string pattern = "abba", s = "dog cat cat dog";
    bool isPattern = wordPattern(pattern, s);

    if (isPattern)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

bool wordPattern(string pattern, string s)
{
    vector<string> split;
    bool isPattern = false;

    splitString(split, s);

    if (pattern.size() == split.size())
    {
        for (int i = 0; i < pattern.size(); i++)
        {
            for (int j = i; j < pattern.size(); j++)
            {
                if (pattern[i] == pattern[j])
                {
                    if (split[i] != split[j])
                    {
                        return false;
                    }
                }
                else
                {
                    if (split[i] == split[j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    return false;
}

void splitString(vector<string> &split, string s)
{
    string temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            split.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }
    split.push_back(temp);
}