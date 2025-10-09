#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int swimInWater(vector<vector<int>> &);

int main(int argc, char const *argv[])
{
    int result = 0;
    vector<vector<int>> grid = {{0, 1, 2, 3, 4},
                                {24, 23, 22, 21, 5},
                                {12, 13, 14, 15, 16},
                                {11, 17, 18, 19, 20},
                                {10, 9, 8, 7, 6}};

    result = swimInWater(grid);
    cout << result << "\n";
    return 0;
}

int swimInWater(vector<vector<int>> &grid)
{
    int nr = 0, nc = 0;
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(grid[0][0], 0, 0);
    vector<pair<int, int>> dirs = {{0, 1},
                                   {1, 0},
                                   {0, -1},
                                   {-1, 0}};

    while (!pq.empty())
    {
        int t, r, c;
        std::tie(t, r, c) = pq.top();
        pq.pop();
        if (visited[r][c])
        {
            continue;
        }

        visited[r][c] = true;

        if (r == n - 1 && c == n - 1)
        {
            return t;
        }

        for (const auto &dir : dirs)
        {
            int dr = dir.first;
            int dc = dir.second;
            nr = r + dr;
            nc = c + dc;

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc])
            {
                pq.emplace(max(t, grid[nr][nc]), nr, nc);
            }
        }
    }

    return -1;
}