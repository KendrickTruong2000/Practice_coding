#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverString(char str[]);

int main(int argc, char const *argv[])
{
    char str[] = " I love C programming";

    reverString(str);
    return 0;
}

void reverString(char str[])
{
    int size = strlen(str);
    char tempStr[size];
    int count = 0;

    for (int i = size; i >= 0; i--)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            for (int j = 0; j <= count; j++)
            {
                tempStr[j] = str[i + j];
                printf("%c", tempStr[j]);
            }

            count = 0;
        }
        else
        {
            count++;
        }
    }
}
