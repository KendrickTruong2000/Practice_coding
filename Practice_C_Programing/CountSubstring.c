#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countSubString(char[], char[]);
int main(int argc, char const *argv[])
{
    char mainString[] = "abcabccbb";
    char subString[] = "abc";
    int result;

    result = countSubString(mainString, subString);
    // printf("%d\n", result); 
    return 0;
}

int countSubString(char mainString[], char subString[])
{
    int mainStringLen = strlen(mainString);
    int subStringLen = strlen(subString);
    int count = 0, countChar = 0;

    for (int i = 0; i < mainStringLen; i++)
    {
        if (mainString[i] == subString[i])
        {
            countChar++;
            printf("%d ", countChar);
            if (countChar == subStringLen)
            {
                count++;
                countChar = 0;
            }
        }
    }

    return count;
}
