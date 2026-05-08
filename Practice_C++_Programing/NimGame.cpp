#include <iostream>

using namespace std;

bool canWinNim(int);

int main(int argc, char const *argv[])
{
    int n = 0;
    bool canWin = false;

    cout << "Please enter number of stone: ";
    cin >> n;
    canWin = canWinNim(n);
    if (canWin == 1)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}

bool canWinNim(int n)
{
    return n % 4 != 0;
}