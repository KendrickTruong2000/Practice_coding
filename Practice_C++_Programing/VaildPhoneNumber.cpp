#include <iostream>
#include <fstream>

using namespace std;

bool isValidPhoneNumber(string &);

int main(int argc, char const *argv[])
{
    string myText;
    bool isValid = false;
    ifstream MyReadFile("file.txt");

    while (getline(MyReadFile, myText))
    {
        isValid = isValidPhoneNumber(myText);

        if (isValid == 1)
        {
            cout << myText << endl;
        }
    }

    MyReadFile.close();

    return 0;
}

bool isValidPhoneNumber(string &phoneNumber)
{
    int length = phoneNumber.length();
    bool isValid = false;

    if (phoneNumber[0] == '(' && phoneNumber[4] == ')')
    {
        if (phoneNumber[5] != ' ' || phoneNumber[9] != '-')
        {
            return false;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                if (i != 5 && i != 9 && i != 0 && i != 4)
                {
                    if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    else
    {
        if (phoneNumber[3] != '-' || phoneNumber[7] != '-')
        {
            return false;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                if (i != 3 && i != 7)
                {
                    if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}