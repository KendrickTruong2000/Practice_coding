#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> letterCombinations(string digits);
void getDigits(int &num1, int &num2, string digits);

int main(int argc, char const *argv[])
{
    string digits = "23";
    vector<string> result = letterCombinations(digits);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

vector<string> letterCombinations(string digits)
{
    vector<string> result = {""};
    vector<string> temp;
    int index = 0;
    vector<vector<string>> keys = {
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"}};

    if (digits.empty())
    {
        return {};
    }

    for (char digit : digits)
    {
        index = digit - '2';

        if (index < 0 || index >= keys.size())
        {
            continue;
        }

        temp.clear(); // Clear temp for each digit
        for (const string &prefix : result)
        {
            for (const string &letter : keys[index])
            {
                temp.push_back(prefix + letter);
            }
        }
        result = temp;
    }

    return result;
}