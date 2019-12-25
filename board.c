#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "list.h"

#define SIZE 5

char * generate_random_boggle_board()
{
    time_t t;
    int i;
    int size = SIZE;

    char *board;
    board = (char *)malloc(size*size*sizeof(char));

    srand((unsigned) time(&t));

    for (i = 0; i < size*size; ++i)
    {
        board[i] = rand() % 26 + 97;
    }

    return board;
}


void print_boggle_board(char *board)
{
    int i,j;

    for (i = 0; i < 5 ; ++i)
    {
        for(j = 0; j < 5 ; ++j)
        {
            printf ("%c ", board[i*5 + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_boggle_board_numbers(char *board)
{
    int i,j;

    for (i = 0; i < 5 ; ++i)
    {
        for(j = 0; j < 5 ; ++j)
        {
            printf ("%02d ", i*5 + j);
        }
        printf("\n");
    }
    printf("\n");
}


IntList *get_neighbors(int n, IntList* ignore)
{
    IntList *neighborList = new_int_list();
    int x = 0;
    int y = 0;
    int i,j;
    int neighbor = 0;

    x = n % SIZE;
    y = n / SIZE;
    // printf("x: %d  y: %d\n\n", x, y);

    for (i = x-1; i < x+2; ++i)
    {
        if ((i < 0)|| (i > SIZE-1))
            continue;

        for (j = y-1; j < y + 2; ++j)
        {
            if ((j < 0)||(j > SIZE-1))
                continue;
            if ((i == x) && (j == y))
                continue;

            neighbor = j*SIZE +i;
            if (in_int_list(ignore, neighbor))
                continue;

            // printf("x: %d  y: %d\n", i, j);
            append_back_int_list(neighborList, neighbor);
        }
    }

    return neighborList;

}


