#include <iostream>
#include <string.h>

using namespace std;

string reverseVowels(string);

int main(int argc, char const *argv[])
{
    string s = "IceCreAm";
    string result = " ";

    // cout << s.size() << endl;
    result = reverseVowels(s);
    cout << result << endl;
    return 0;
}

string reverseVowels(string s)
{
    int left = 0;
    int right = s.size() - 1;

    string vowels = "aeiouAEIOU";

    while (left < right)
    {
        while (left < right && vowels.find(s[left]) == string::npos)
        {
            left++;
        }

        while (left < right && vowels.find(s[right]) == string::npos)
        {
            right--;
        }

        swap(s[left], s[right]);

        left++;
        right--;
    }

    return s;
}