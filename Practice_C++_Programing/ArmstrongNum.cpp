#include <iostream>
#include <math.h>

using namespace std;

bool CheckArmstrong(int);

int main(int argc, char const *argv[])
{
    int num = 0;
    bool isArmstrong = false;

    cout << "Please enter an integer number: ";
    cin >> num;

    isArmstrong = CheckArmstrong(num);
    if (isArmstrong == false)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }

    return 0;
}

bool CheckArmstrong(int num)
{
    int unitNum = 0, result = 0, inputNum = 0;
    bool isArmstrong = false;

    inputNum = num;
    unitNum = num % 10;

    while (inputNum != 0)
    {
        result += pow(inputNum % 10, unitNum);
        inputNum = inputNum / 10;
    }

    if (result == num)
    {
        isArmstrong = true;
    }

    return isArmstrong;
}
