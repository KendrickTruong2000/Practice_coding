#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int trapRainWater(vector<vector<int>> &heightMap);
int findMin(vector<int> &);

int main(int argc, char const *argv[])
{
    vector<vector<int>> heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    int result;
    result = trapRainWater(heightMap);
    cout << result << "\n";

    return 0;
}

int trapRainWater(vector<vector<int>> &heightMap)
{
    int trapped = 0, nrows = 0, ncols = 0, orgHeight = 0;
    int rows = heightMap.size();
    int cols = heightMap[0].size();
    vector<int> map;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visitied(rows, vector<bool>(cols, false));
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>>
        minHeap;

    for (int i = 0; i < rows; ++i)
    {
        for (int j : {0, cols - 1})
        {
            minHeap.push({heightMap[i][j], i, j});
            visitied[i][j] = true;
        }
    }

    for (int j = 0; j < cols - 1; ++j)
    {
        for (int i : {0, rows - 1})
        {
            minHeap.push({heightMap[i][j], i, j});
            visitied[i][j] = true;
        }
    }

    while (!minHeap.empty())
    {
#if __cplusplus >= 201703L
        auto [h, r, c] = minHeap.top();
#else
        int h, r, c;
        std::tie(h, r, c) = minHeap.top();
#endif
        minHeap.pop();

        for (auto &d : dirs)
        {
            nrows = r + d[0];
            ncols = c + d[1];

            if (nrows < 0 || nrows >= rows || ncols < 0 || ncols >= cols || visitied[nrows][ncols])
            {
                continue;
            }

            visitied[nrows][ncols] = true;
            orgHeight = heightMap[nrows][ncols];
            if (orgHeight < h)
            {
                trapped += h - orgHeight;
            }
            minHeap.push({max(h, orgHeight), nrows, ncols});
        }
    }

    return trapped;
}