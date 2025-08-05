#include <iostream>

using namespace std;

string ReverseString(string str);

int main(int argc, char const *argv[])
{
    string str, ReverStr;

    cout << "Please enter a string: ";
    cin >> str;

    ReverStr = ReverseString(str);

    cout << ReverStr << endl;

    return 0;
}

string ReverseString(string str)
{
    string ReverStr;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        ReverStr += str[i];
    }

    return ReverStr;
}