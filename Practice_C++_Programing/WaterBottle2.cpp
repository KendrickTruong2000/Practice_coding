#include <iostream>

using namespace std;

int maxBottlesDrunk(int, int);

int main(int argc, char const *argv[])
{
    int numBottles, exchangeBottles, maxBottles;
    cout << "Please enter number of bottles you have: ";
    cin >> numBottles;
    cout << "Please enter number of exchange bottles: ";
    cin >> exchangeBottles;
    maxBottles = maxBottlesDrunk(numBottles, exchangeBottles);
    cout << maxBottles << "\n";
    return 0;
}

int maxBottlesDrunk(int numBottles, int exchangeBottles)
{
    int bottlesDrunk = numBottles, emptyBottles = numBottles;

    if ((numBottles >= 1 && numBottles <= 100) && (exchangeBottles >= 1 && exchangeBottles <= 100))
    {
        while (emptyBottles >= exchangeBottles)
        {
            emptyBottles -= exchangeBottles - 1;
            bottlesDrunk++;
            exchangeBottles++;
        }
    }
    return bottlesDrunk;
}
