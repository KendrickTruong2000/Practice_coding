#include <iostream>

using namespace std;

int CountVowels(string str);

int main(int argc, char const *argv[])
{
    int vowelCount = 0;
    string str;

    cout << "Please enter a string: ";
    cin >> str;

    vowelCount = CountVowels(str);

    cout << vowelCount;

    return 0;
}

int CountVowels(string str)
{
    int vowelCount = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowelCount++;
        }
        else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            vowelCount++;
        }
    }

    return vowelCount;
}
