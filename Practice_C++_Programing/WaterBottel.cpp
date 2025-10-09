#include <iostream>

using namespace std;

int numsWaterBottles(int, int);

int main(int argc, char const *argv[])
{
    int numBottles, numExchange, result;

    cout << "Please enter number of number bottles: ";
    cin >> numBottles;
    cout << "Please enter number of number exchange: ";
    cin >> numExchange;
    result = numsWaterBottles(numBottles, numExchange);
    cout << result << "\n";
    return 0;
}

int numsWaterBottles(int numBottles, int numExchange)
{
    int drinkBottles = 0;

    if ((numBottles >= 1 && numBottles <= 100) && (numExchange >= 2 && numExchange <= 100))
    {
        while (numBottles >= numExchange)
        {
            numBottles -= numExchange;
            drinkBottles += numExchange;
            numBottles++;
        }

        return drinkBottles + numBottles;
    }
}
