#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p);

int main(int argc, char const *argv[])
{
    string s = "ab";
    string p = "c*a*b";

    bool result = isMatch(s, p);

    if (result == 1)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

bool isMatch(string s, string p)
{
    int m = (int)s.size();
    int n = (int)p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[m][n] = true;

    // fill table bottom-up
    for (int i = m; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            bool first_match = (i < m) && (p[j] == s[i] || p[j] == '.');

            if (j + 1 < n && p[j + 1] == '*')
            {
                // zero occurrence of p[j] (dp[i][j+2]) OR
                // one/more occurrence: first_match && dp[i+1][j]
                dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
            }
            else
            {
                dp[i][j] = first_match && dp[i + 1][j + 1];
            }
        }
    }

    return dp[0][0];
}
