#include <iostream>
#include <string.h>

using namespace std;

int myAtoi(string);
void removeSpace(string *);

int main(int argc, char const *argv[])
{
    string str;
    int num;

    cout << "Please enter a number as a string: ";
    cin >> str;

    num = myAtoi(str);
    cout << num << "\n";
    return 0;
}

int myAtoi(string str)
{
    int i = 0, sign = 1, num = 0;
    // Skip leading whitespace
    while (i < str.length() && str[i] == ' ')
        i++;
    // Handle sign
    if (i < str.length() && (str[i] == '-' || str[i] == '+'))
    {
        sign = (str[i++] == '-') ? -1 : 1;
    }
    // Convert digits (stop at non-digit)
    while (i < str.length() && isdigit(str[i]))
    {
        // Check for overflow (critical!)
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] > '7'))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        num = num * 10 + (str[i++] - '0');
    }
    return sign * num;
}

// void removeSpace(string *str)
// {
//     int count = 0;
//     for (int i = 0; i < str->length(); i++)
//     {
//         if (((*str)[i] != ' ') && ((*str)[i + 1] != ' '))
//         {
//             (*str)[count++] = (*str)[i];
//         }
//     }
//     str->resize(count);
// }

// int myAtoi(string str)
// {
//     long long num = 0;
//     int sign = 1;
//     removeSpace(&str);
//     for (int i = 0; i < str.length(); i++)
//     {
//         if ((str[i] == 45 || str[i] == 43) && i == 0)
//         {
//             if (str[i] == 45)
//             {
//                 sign = -1;
//             }

//             if (str[i] == 43)
//             {
//                 sign = 1;
//             }

//             continue;
//         }
//         if (str[i] >= 48 && str[i] <= 57)
//         {
//             num = num * 10 + (str[i] - '0');

//             if (num > INT32_MAX)
//             {
//                 return sign == 1 ? INT32_MAX : INT32_MIN;
//             }
//         }
//         else
//         {
//             break;
//         }
//     }
//     num *= sign;

//     if (num < INT32_MIN)
//         return INT32_MIN;
//     if (num > INT32_MAX)
//         return INT32_MAX;

//     return (int)num;
// }