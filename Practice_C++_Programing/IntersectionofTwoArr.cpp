#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int> &, vector<int> &);
vector<int> uniqueValues(vector<int> &);

int main(int argc, char const *argv[])
{
    vector<int> num1 = {1, 2, 2, 1};
    vector<int> num2 = {2, 2};
    vector<int> result;

    result = intersection(num1, num2);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

vector<int> intersection(vector<int> &num1, vector<int> &num2)
{
    sort(num1.begin(), num1.end());
    sort(num2.begin(), num2.end());

    int p1 = 0;
    int p2 = 0;
    int i = 0;
    vector<int> intersect;

    while (p1 < num1.size() && p2 < num2.size())
    {
        if (num1[p1] == num2[p2])
        {
            intersect.push_back(num1[p1]);
            i++;
            p1++;
            p2++;
        }
        else if (num1[p1] < num2[p2])
        {
            p1++;
        }
        else
        {
            p2++;
        }
    }

    // sort(intersect.begin(), intersect.end());
    // intersect.erase(unique(intersect.begin(), intersect.end()), intersect.end());

    return intersect;
}