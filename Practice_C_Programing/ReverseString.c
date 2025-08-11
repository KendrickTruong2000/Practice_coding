#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReverseString(char *, int);

int main(int argc, char const *argv[])
{
    char str[] = "Hello";
    int length = strlen(str);
    ReverseString(str, length);
    printf("Reversed string is: ");

    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }

    return 0;
}

void ReverseString(char *str, int length)
{
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
