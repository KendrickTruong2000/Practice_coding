#include <iostream>

using namespace std;

int FactorialNumber(int num);

int main(int argc, char const *argv[])
{
    int num = 0, factorial = 0;

    cout << "Please enter a possitive number: ";
    cin >> num;

    factorial = FactorialNumber(num);

    cout << factorial << endl;

    return 0;
}

int FactorialNumber(int num)
{
    int result = 1;

    if (num != 0)
    {
        for (int i = 1; i <= num; i++)
        {
            result = result * i;
        }
    }
    else
    {
        result = 1;
    }

    return result;
}