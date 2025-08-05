#include <iostream>

using namespace std;

void my_strcpy(string *, const string *);

int main(int argc, char const *argv[])
{
    string src = "Hello World", dest;

    my_strcpy(&dest, &src);

    cout << dest;

    return 0;
}

void my_strcpy(string *dest, const string *src)
{
    for (int i = 0; i < src->length(); i++)
    {
        dest[i] = src[i];
    }
}