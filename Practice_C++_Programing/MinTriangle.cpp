#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>> &);
int findMininum(vector<int> &, int &);

int main(int argc, char const *argv[])
{
    int result = 0;

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    // vector<vector<int>> triangle = {{-10}};

    result = minimumTotal(triangle);

    cout << result << "\n";

    return 0;
}

int findMinimum(vector<int> &triangle, int &index)
{
    int length = triangle.size();
    int min = triangle[0];

    if (length == 1)
    {
        return min;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (triangle[i] < min)
            {
                min = triangle[i];
                index = i;
            }
        }
    }

    return min;
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int sum = 0, min = 0, index = 0;
    int length = triangle.size();

    if ((length >= 1 && length <= 100) && (triangle[0].size() == 1))
    {
        for (int i = 0; i < length; i++)
        {
            if (triangle[i].size() == triangle[i - 1].size() + 1)
            {
                min = findMinimum(triangle[i], index);
                sum += min;
            }
        }
    }

    return sum;
}
