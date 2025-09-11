#include <iostream>
#include <string>

using namespace std;

string zigzagConvert(string, int);

int main(int argc, char const *argv[])
{
    string str, result;
    int rows;

    cout << "Please enter a string: ";
    cin >> str;
    cout << "Please enter number of rows: ";
    cin >> rows;

    result = zigzagConvert(str, rows);
    cout << result;

    return 0;
}

string zigzagConvert(string str, int rows)
{
    if (rows <= 1 || str.length() <= rows)
    {
        return str;
    }
    vector<string> tempStr(rows);
    int currRow = 0;
    bool goingDown = false;
    for (char c : str)
    {
        tempStr[currRow] += c;
        if (currRow == 0 || currRow == rows - 1)
            goingDown = !goingDown;
        currRow += goingDown ? 1 : -1;
    }
    string result;
    for (const string &row : tempStr)
    {
        result += row;
    }
    return result;
}
