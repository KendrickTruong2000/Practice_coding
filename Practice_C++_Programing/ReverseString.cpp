#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char> &);

int main(int argc, char const *argv[])
{
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    reverseString(str);

    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    return 0;
}

void reverseString(vector<char> &s)
{
    vector<char> revStr(s.size());

    for (int i = 0; i < s.size(); i++)
    {
        revStr[i] = s[s.size() - 1 - i];
    }

    for (int i = 0; i < revStr.size(); i++)
    {
        s[i] = revStr[i];
    }
}