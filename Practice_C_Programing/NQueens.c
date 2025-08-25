#include <stdio.h>
#include <stdlib.h>

int placeNQueens(int n, int board[n][n]);
void printBoard(int n, int board[n][n]);

int main(int argc, char const *argv[])
{
    int n;
    printf("Please enter value for n: ");
    scanf("%d", &n);

    int board[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if (placeNQueens(n, board))
    {
        printBoard(n, board);
    }
    else
    {
        printf("There are not solution for %d", n);
    }

    return 0;
}

int placeNQueens(int n, int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i + 1][j] != 1 || board[i - 1][j] != 1)
            {
                if (board[i][j + 1] != 1 || board[i][j - 1] != 1)
                {
                    if (board[i - j + 1][j] != 1 || board[i - j - 1][j] != 1)
                    {
                        if (board[i + j + 1][j] != 1 || board[i + j - 1][j] != 1)
                        {
                            board[i][j] = 1;
                            printf("The Queen is placed here (%d, %d)\n", i, j);
                        }
                    }
                }
            }
        }
    }

    return 1;
}

void printBoard(int n, int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                printf("|Q");
            }
            else
            {
                printf("| ");
            }
        }
        printf("|\n");
    }
}
