#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void ReverseSentence(vector<string> *);

int main(int argc, char const *argv[])
{
    vector<string> inputSen;
    string line, word;

    cout << "Please enter a sentence: ";
    getline(cin, line);

    stringstream ss(line);
    while (ss >> word)
    {
        inputSen.push_back(word);
    }

    ReverseSentence(&inputSen);

    return 0;
}

void ReverseSentence(vector<string> *sentence)
{ 
    for (int i = sentence->size() - 1; i >= 0; --i)
    {
        cout << (*sentence)[i];
        if (i != 0)
        {
            cout << " ";
        }
    }
    cout << endl;
}