#include <iostream>
#include <vector>

using namespace std;

int max(vector<int> &prices);
int maxProfit(vector<int> &price);

int main(int argc, char const *argv[])
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = maxProfit(prices);

    cout << profit << endl;

    return 0;
}

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices)
    {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}