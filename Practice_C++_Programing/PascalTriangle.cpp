#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex);
vector<vector<int>> generate(int numRows);

int main(int argc, char const *argv[])
{
    int numRows = 5, rowIndex = 3;
    vector<vector<int>> result = generate(numRows);
    vector<int> row = getRow(rowIndex);

    for (int num : row)
    {
        cout << num << " ";
    }
    cout << endl;

    for (const auto &row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;

    if (numRows == 0)
    {
        return result;
    }

    result.push_back({1});

    for (int i = 1; i < numRows; i++)
    {
        vector<int> rows = {1};

        for (int j = 1; j < result.back().size(); j++)
        {
            // cout << result.back()[j - 1] + result.back()[j] << " ";
            rows.push_back(result.back()[j - 1] + result.back()[j]);
        }
        // cout << endl;
        rows.push_back(1);
        result.push_back(rows);
    }

    return result;
}

vector<int> getRow(int rowIndex)
{
    vector<int> row;
    vector<vector<int>> pascal;

    if (rowIndex == 0)
    {
        return row;
    }

    row.push_back({1});
    pascal.push_back({1});

    for (int i = 1; i <= rowIndex; i++)
    {
        vector<int> rows = {1};

        for (int j = 1; j < pascal.back().size(); j++)
        {
            // cout << pascal.back()[j - 1] + pascal.back()[j] << " ";
            rows.push_back(pascal.back()[j - 1] + pascal.back()[j]);
        }
        // cout << endl;
        rows.push_back(1);
        pascal.push_back(rows);
    }

    row = pascal.back();

    return row;
}