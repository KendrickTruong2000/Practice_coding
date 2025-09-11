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

    removeSpace(&str);
    num = myAtoi(str);
    cout << num << "\n";
    return 0;
}

void removeSpace(string *str)
{
    int count = 0;
    for (int i = 0; i < str->length(); i++)
    {
        if ((*str)[i] != ' ')
        {
            (*str)[count++] = (*str)[i];
        }
    }
    str->resize(count);
}

int myAtoi(string str)
{
    int num = 0, sign = 1;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 48 && str[i] <= 57 || str[i] == 45)
        {
            if (str[i] == 45)
            {
                sign = -1;
            }
            else
            {
                num = num * 10 + (str[i] - '0');
            }
        }
        else
        {
            break; 
        }
    }

    return num * sign;
}