// #include <iostream>
// #include <string>

// using namespace std;

// bool checkPalindrom(string);
// string longestPalindrom(string);
// string copyString(string, int, int);

// int main(int argc, char const *argv[])
// {
//     string str;
//     cout << "Please eneter a string: ";
//     cin >> str;

//     cout << "Longest palindrome: " << longestPalindrom(str) << endl;

//     return 0;
// }

// string longestPalindrom(string str)
// {
//     bool isPalindrom = false;
//     int k = str.length();
//     int max_len = 0;
//     string tempSub = " ", palindromStr = " ";

//     for (int i = 0; i < k; i++)
//     {
//         for (int j = i; j < k; j++)
//         {
//             tempSub = copyString(str, i, j + 1);
//             if (checkPalindrom(tempSub) && tempSub.length() > max_len)
//             {
//                 max_len = tempSub.length();
//                 palindromStr = tempSub;
//             }
//         }
//     }

//     return palindromStr;
// }

// string copyString(string src, int from, int to)
// {
//     string dst = "";
//     for (int i = from; i < to; i++)
//     {
//         dst += src[i];
//     }
//     return dst;
// }
// bool checkPalindrom(string str)
// {
//     for (int i = 0; i < str.length() / 2; i++)
//     {
//         if (str[i] != str[str.length() - 1 - i])
//         {
//             return false;
//         }
//     }
//     return true;
// }

#include <iostream>
#include <string>

using namespace std;

string longestPalindrom(string s);
pair<int, int> expandAroundCenter(string s, int left, int right);

int main(int argc, char const *argv[])
{
    string str;
    cout << "Please enter a string: ";
    cin >> str;

    cout << "Longest palindrome: " << longestPalindrom(str) << endl;

    return 0;
}

string longestPalindrom(string s)
{
    if (s.length() < 2)
        return s;
    
    int start = 0, maxLen = 1;
    
    // Check all possible centers
    for (int i = 0; i < s.length(); i++)
    {
        // Odd-length palindromes (single character center)
        auto [left1, right1] = expandAroundCenter(s, i, i);
        int len1 = right1 - left1 + 1;
        
        // Even-length palindromes (two character center)
        auto [left2, right2] = expandAroundCenter(s, i, i + 1);
        int len2 = right2 - left2 + 1;
        
        if (len1 > maxLen)
        {
            start = left1;
            maxLen = len1;
        }
        if (len2 > maxLen)
        {
            start = left2;
            maxLen = len2;
        }
    }
    
    return s.substr(start, maxLen);
}

pair<int, int> expandAroundCenter(string s, int left, int right)
{
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }
    // Return valid indices (left and right went one step too far)
    return {left + 1, right - 1};
}