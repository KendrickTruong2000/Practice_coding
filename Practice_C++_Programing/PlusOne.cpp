#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> plusOne(vector<int> &);

int main(int argc, char const *argv[])
{
    vector<int> digits = {1, 2, 3};
    vector<int> result;

    plusOne(digits);

    for (int i = 0; i < digits.size(); i++)
    {
        cout << digits[i];
    }
    cout << endl;

    return 0;
}

vector<int> plusOne(vector<int> &digits)
{
    // this code can only handle to limited number (19+ digits)
    // vector<int> result;
    // int length = digits.size();
    // long int num = 0, digit = 0, j = 0;
    // // cout << length << endl;

    // for (int i = 0; i < length; i++)
    // {
    //     num += (pow(10, length - 1 - i) * digits[i]);
    // }

    // // Plus one
    // num += 1;

    // while (num != 0)
    // {
    //     digit = num % 10;
    //     num = num / 10;
    //     // cout << digit << endl;
    //     result.insert(result.begin(), digit);
    // }

    // return result;

    int n = digits.size();

    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] < 9)
        {
            digits[i] += 1;
            return digits;
        }
        digits[i] = 0;
    }

    digits.insert(digits.begin(), 1);
    return digits;
}
