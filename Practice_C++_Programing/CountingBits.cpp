#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int);

int main(int argc, char const *argv[])
{
    vector<int> ans;

    ans = countBits(5);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}

vector<int> countBits(int n)
{
    vector<int> ans(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
}