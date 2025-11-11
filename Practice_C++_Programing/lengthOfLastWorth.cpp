#include <iostream>
#include <string.h>

using namespace std;

int lengthOfLastWorld(string);

int main(int argc, char const *argv[])
{
    string s = "a";
    int result = 0;
    result = lengthOfLastWorld(s);
    cout << result << endl;
    return 0;
}

int lengthOfLastWorld(string s)
{
    // int i = s.length() - 1, count = 0;
    // while (i >= 0 && s[i] == ' ')
    // {
    //     i--;
    // }

    // while (s[i] != ' ' && i >= 0)
    // {
    //     count++;
    //     i--;
    // }
    // return count;

    // Find last non-space character
    int lastPos = s.find_last_not_of(' ');
    if (lastPos == string::npos)
        return 0; // All spaces

    // Find the space before the last word
    int spacePos = s.rfind(' ', lastPos);

    // Return length of last word
    return lastPos - spacePos;
}
