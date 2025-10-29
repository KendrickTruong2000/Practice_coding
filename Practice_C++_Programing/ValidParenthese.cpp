#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string);

int main(int argc, char const *argv[])
{
    bool isCorrect = false;
    string s = "[";

    isCorrect = isValid(s);

    if (isCorrect == 1)
    {
        cout << "True" << "\n";
    }
    else
    {
        cout << "False" << "\n";
    }

    return 0;
}

bool isValid(string s)
{
    stack<char> st;
    char top;

    if (s.length() < 1 || s.length() > 10000)
    {
        return false;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            top = st.top();
            st.pop();

            if ((s[i] == ')' && top != '(') ||
                (s[i] == '}' && top != '{') ||
                (s[i] == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return st.empty();
}
