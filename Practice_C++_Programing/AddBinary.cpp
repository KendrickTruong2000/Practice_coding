#include <iostream>
#include <string>

using namespace std;

string addBinary(string, string);

int main(int argc, char const *argv[])
{
    string binary1 = "1010";
    string binary2 = "1011";
    string result;
    result = addBinary(binary1, binary2);

    cout << result << endl;
    return 0;
}

string addBinary(string a, string b)
{
    string result;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += a[i--] - '0';
        }

        if (j >= 0)
        {
            sum += b[j--] - '0';
        }

        result.push_back(char('0' + (sum & 1)));
        carry = sum >> 1;
    }

    reverse(result.begin(), result.end());

    return result;
}