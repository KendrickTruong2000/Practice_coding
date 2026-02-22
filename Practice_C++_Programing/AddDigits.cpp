#include <iostream>

using namespace std;

int sum(int num);
int addDigits(int num);

int main(int argc, char const *argv[])
{
    int num = 38;
    int result = addDigits(num);
    cout << result << endl;
    return 0;
}

int sum(int num)
{
    int temp = 0, sum = 0;

    while (num != 0)
    {
        temp = num % 10;
        sum += temp;
        num /= 10;
    }

    return sum;
}

int addDigits(int num)
{
    int temp = 0, result = 0;

    if (num <= 9)
    {
        return num;
    }
    
    while (num >= 10)
    {
        num = sum(num);
        result = num;
    }
    
    return result;
}