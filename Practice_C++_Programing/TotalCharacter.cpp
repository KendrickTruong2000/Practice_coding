#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lengthAfterTransformation(string s, int t);

int main(int argc, char const *argv[])
{
    string s = "jqktcurgdvlibczdsvnsg";
    int t = 7517;
    int result = 0;
    cout << s << "\n";
    result = lengthAfterTransformation(s, t);
    cout << result << "\n";
    return 0;
}

int lengthAfterTransformation(string s, int t)
{
    const long long MOD = 1e9 + 7;
    vector<long long> count(26, 0);
    for (char c : s)
        count[c - 'a']++;

    for (int step = 0; step < t; step++)
    {
        long long new_a = count[25] % MOD;
        long long new_b = count[25] % MOD;
        vector<long long> next(26, 0);
        for (int i = 0; i < 25; ++i)
        {
            next[i + 1] = count[i] % MOD;
        }
        next[0] = (next[0] + new_a) % MOD;
        next[1] = (next[1] + new_b) % MOD;
        count = next;
    }

    long long total = 0;
    for (int i = 0; i < 26; ++i)
    {
        total = (total + count[i]) % MOD;
    }
    return total;
}