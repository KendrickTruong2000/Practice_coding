#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string myText;
    ifstream MyReadFile("file.txt");

    while (getline(MyReadFile, myText))
    {
        cout << myText << endl;
    }

    MyReadFile.close();
    
    return 0;
}
