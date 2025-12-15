#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);

// vector<int> mergeSorted(const vector<int> &a, const vector<int> &b)
// {
//     int i = 0, j = 0;
//     vector<int> out;
//     out.reserve(a.size() + b.size());
//     while (i < (int)a.size() && j < (int)b.size())
//     {
//         if (a[i] <= b[j])
//             out.push_back(a[i++]);
//         else
//             out.push_back(b[j++]);
//     }
//     while (i < (int)a.size())
//         out.push_back(a[i++]);
//     while (j < (int)b.size())
//         out.push_back(b[j++]);
//     return out;
// }

int main()
{
    vector<int> num1 = {1, 2, 3, 0, 0, 0};
    vector<int> num2 = {2, 5, 6};
    int m = num1.size();
    int n = num2.size();
    merge(num1, m, num2, n);
    // for (int x : num1)
    //     cout << x << ' ';
    // cout << '\n';
    return 0;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0, k = 0;
    vector<int> out;
    out.reserve(m + n);

    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            out.push_back(nums1[i++]);
        }
        else
        {
            out.push_back(nums2[j++]);
        }
    }
    // Add remaining elements (no need for != 0 checks)
    while (i < m)
        out.push_back(nums1[i++]);
    while (j < n)
        out.push_back(nums2[j++]);

    // Copy to nums1 (NOT nums2!)
    nums1 = out;

    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
}