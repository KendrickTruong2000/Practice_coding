#include <stdio.h>
#include <string.h>

int IsPalindrome(char *str, int length);

int main(int argc, char const *argv[])
{
    char str[100];
    int length = 0, isPalindrome = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character
    length = strlen(str);
    isPalindrome = IsPalindrome(str, length);

    if (isPalindrome)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}

int IsPalindrome(char *str, int length)
{
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            printf("The string is not a palindrome.\n");
            return 0;
        }
        start++;
        end--;
    }

    printf("The string is a palindrome.\n");
    return 1;
}