#include <iostream>

using namespace std;

int reverseBits(int n);

int main(int argc, char const *argv[])
{
    int n = 13;
    int result = reverseBits(n);

    cout << result << endl;

    return 0;
}

int reverseBits(int n)
{
    uint32_t x = static_cast<uint32_t>(n);
    uint32_t result = 0;

    for (int i = 0; i < 32; i++)
    {
        result = (result << 1) | (x & 1);
        x >>= 1;
    }

    return result;
}