#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kmpAlgorithm(const char *text, const char *pattern);

int main(int argc, char const *argv[])
{
    char text[] = "ABABDABABCABABDABABCABAB";
    char pattern[] = "ABABCABAB";
    kmpAlgorithm(text, pattern);
    return 0;
}

void kmpAlgorithm(const char *text, const char *pattern)
{
    int textSize = strlen(text);
    int patternSize = strlen(pattern);
    int j = 0; // index for pattern
    int arr[patternSize];

    for (int i = 0; i <= textSize - patternSize; i++)
    {
        j = 0;
        while (j < patternSize && text[i + j] == pattern[j])
        {
            j++;

            if (j == patternSize)
            {
                printf("Pattern found at index %d\n", i);
                arr[i] = 1; // Mark the index where pattern is found
                break;
            }
        }
    }
}