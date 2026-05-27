#include <iostream>

using namespace std;

int guessNumber(int);

int main(int argc, char const *argv[])
{
    int n = 10;
    guessNumber(n);
    return 0;
}

int guessNumber(int n)
{
    int Low = 1, High = n;

    while (Low < High)
    {
        int Mid = Low + (High - Low) / 2;
        int Value = guess(Mid);

        // Mid is smaller
        if (Value == 1)
        {
            Low = Mid + 1;
        }
        else if (Value == -1)
        {
            High = Mid - 1;
        }
        else
        {
            return Mid;
        }
    }

    return Low;
}