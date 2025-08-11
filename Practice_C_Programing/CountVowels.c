#include <stdio.h>
#include <string.h>
#include <ctype.h>

int CountVowels(char *str, int length);

int main(int argc, char const *argv[])
{
    char str[100];
    int length = 0, vowelCount = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character
    length = strlen(str);
    vowelCount = CountVowels(str, length);
    printf("Number of vowels: %d\n", vowelCount);

    return 0;
}

int CountVowels(char *str, int length)
{
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        str[i] = tolower(str[i]);
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            count++;
        }
    }

    return count;
}