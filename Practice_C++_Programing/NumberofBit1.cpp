#include <iostream>
#include <string.h>

using namespace std;

int hammingWeight(int n);

int main(int argc, char const *argv[])
{
    int n = 13;
    int result = hammingWeight(n);

    cout << result << endl;

    return 0;
}

int hammingWeight(int n)
{
    string result = "";
    int weight = 0;

    if (n == 0)
    {
        cout << "0";
        return 0;
    }

    while (n > 0)
    {
        int bit = n & 1;
        if (bit == 1)
        {
            weight++;
        }
        
        n >>= 1;
    }

    return weight;
}