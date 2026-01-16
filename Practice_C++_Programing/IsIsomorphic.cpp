#include <iostream>
#include <string.h>

using namespace std;

bool isIsomorphic(string s, string t);

int main(int argc, char const *argv[])
{
    string s = "egg";
    string t = "add";
    bool result = isIsomorphic(s, t);

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

bool isIsomorphic(string s, string t)
{
    int mapST[256] = {0};
    int mapTS[256] = {0};

    if (s.size() != t.size())
    {
        return false;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (mapST[s[i]] != mapTS[t[i]])
        {
            return false;
        }

        mapST[s[i]] = i + 1;
        mapTS[t[i]] = i + 1;
        
    }
    
    return true;
}