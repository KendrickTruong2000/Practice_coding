#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backTrack(int open, int close, int n, string current, vector<string> &result);
vector<string> generateParanthesis(int n);

int main(int argc, char const *argv[])
{
    int n = 3;
    vector<string> result = generateParanthesis(n);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    cout << endl;

    return 0;
}

void backTrack(int open, int close, int n, string current, vector<string> &result)
{
    if (current.length() == 2 * n)
    {
        result.push_back(current);
        return;
    }

    if (open < n)
    {
        backTrack(open + 1, close, n, current + "(", result);
    }

    if (close < open)
    {
        backTrack(open, close + 1, n, current + ")", result);
    }
}

vector<string> generateParanthesis(int n)
{
    vector<string> result;
    backTrack(0, 0, n, "", result);

    return result;
}
