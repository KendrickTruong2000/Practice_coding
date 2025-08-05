#include <iostream>
#include <algorithm>

using namespace std;

void CountCharacter(string);

int main(int argc, char const *argv[])
{
    string inputString;

    cout << "Please enter a string: ";
    cin >> inputString;

    CountCharacter(inputString);

    return 0;
}

void CountCharacter(string str)
{
    vector<char> characters;
    char currentCharacter;
    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        currentCharacter = str[i];

        if (find(characters.begin(), characters.end(), currentCharacter) == characters.end())
        {
            characters.push_back(currentCharacter);

            for (int j = i; j < str.length(); j++)
            {
                if (currentCharacter == str[j])
                {
                    count++;
                }
            }
        }

        if (count > 0)
        {
            cout << currentCharacter << ":" << count << " ";
            count = 0;
        }
        else
        {
            continue;
        }
    }
}