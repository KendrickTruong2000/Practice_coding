#include <iostream>

using namespace std;

void FindPrime(int);

int main(int argc, char const *argv[])
{
    int num;

    cout << "Please enter an integer number: ";
    cin >> num;

    FindPrime(num);

    return 0;
}

void FindPrime(int num)
{
    bool isPrime = true;
    int countDividable = 0;

    for (int i = 2; i <= num; i++)
    {
        // cout << i << " ";
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                // cout << j << " ";
                countDividable++;
                if (countDividable > 2)
                {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime == true)
        {
            cout << i << " ";
        }
        countDividable = 0;
        isPrime = true;
    }
}