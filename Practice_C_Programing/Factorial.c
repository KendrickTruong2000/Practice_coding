#include <stdio.h>

int CalFactorial(int n);

int main(int argc, char const *argv[])
{
    int num = 0, numFactorial = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    numFactorial = CalFactorial(num);
    printf("Factorial of %d is: %d\n", num, numFactorial);

    return 0;
}

int CalFactorial(int n)
{
    int result = 1;

    if (n < 0)
    {
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }

    return result;
}