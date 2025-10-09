#include <iostream>
#include <vector>

using namespace std;

long long minTime(vector<int> &, vector<int> &);

int main(int argc, char const *argv[])
{
    vector<int> skill = {1, 5, 2, 4};
    vector<int> mana = {5, 1, 4, 2};
    long long result;
    result = minTime(skill, mana);
    cout << result << "\n";
    return 0;
}

long long minTime(vector<int> &skill, vector<int> &mana)
{
    int n = skill.size();
    int m = mana.size();
    long long currentTime = 0;
    vector<long long> time(n, 0);

    for (int i = 0; i < m; i++)
    {
        currentTime = 0;
        cout << "Current Time: ";
        for (int j = 0; j < n; j++)
        {
            currentTime = max(currentTime, time[j]) + skill[j] * mana[i];
            cout << currentTime << " ";
        }
        cout << "\n";

        time[n - 1] = currentTime;
        cout << "Time: ";
        for (int z = n - 2; z >= 0; z--)
        {
            time[z] = time[z + 1] - skill[z + 1] * mana[i];
            cout << time[z] << " ";
        }
        cout << "\n";
    }

    return time[n - 1];
}
