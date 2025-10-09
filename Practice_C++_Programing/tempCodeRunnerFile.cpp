long long minTime(vector<int> &skill, vector<int> &mana)
{
    int n = skill.size();
    int m = mana.size();
    long long currentTime = 0;
    vector<long long> time(n, 0);

    for (int i = 0; i < n; i++)
    {
        currentTime = 0;
        for (int j = 0; j < m; j++)
        {
            currentTime = max(currentTime, time[i]) + skill[i] * mana[j];

        }

        time[n-1] = currentTime;

        for (int j = n - 2; j >= 0; j--)
        {
            time[j] = time[j+1] - skill[j+1]*mana[i];
        }
    }

    return time[n-1];
}