#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "list.h"

// For now we have a fixed 5x5 grid board (maybe this will become dynamic?)
#define SIZE 5

/* Generate a random array of letters to use as a boggle board */
char * generate_random_boggle_board()
{
    time_t t;
    int i;

    // Store the board in a character array
    char *board;
    board = (char *)malloc(SIZE*SIZE*sizeof(char));

    // Seed the random number generator (this isn't good for simultaneous runs)
    srand((unsigned) time(&t));

    for (i = 0; i < SIZE*SIZE; ++i)
    {
        board[i] = rand() % 26 + 97;
    }

    return board;
}

/* Print a text representation of the boggle board */
void print_boggle_board(char *board)
{
    int i,j;

    for (i = 0; i < SIZE ; ++i)
    {
        for(j = 0; j < SIZE ; ++j)
        {
            printf ("%c ", board[i*SIZE + j]);
        }
        printf("\n");
    }
    printf("\n");

}

/* Print the array number in the board grid for checking and debugging */
void print_boggle_board_numbers(char *board)
{

    int i,j;

    for (i = 0; i < SIZE ; ++i)
    {
        for(j = 0; j < SIZE ; ++j)
        {
            printf ("%02d ", i*SIZE + j);
        }
        printf("\n");
    }
    printf("\n");

}

/* Get a list of the neighbors for a given square */
IntList *get_neighbors(int n, IntList* ignore)
{

    IntList *neighborList = new_int_list();
    int x = 0;
    int y = 0;
    int i,j;
    int neighbor = 0;

    // Convert the array position to a row/col value
    x = n % SIZE;
    y = n / SIZE;

    for (i = x-1; i < x+2; ++i)
    {
        if ((i < 0)|| (i > SIZE-1))
            continue;

        for (j = y-1; j < y + 2; ++j)
        {

            // Skip cols and rows outside of our grid boundaries
            if ((j < 0)||(j > SIZE-1))
                continue;

            // Skip the original square
            if ((i == x) && (j == y))
                continue;

            // Convert the col/row value to an array entry
            neighbor = j*SIZE +i;

            // Skip entries in the ignore list
            if (in_int_list(ignore, neighbor))
                continue;

            // Append whats left to the neighbor list
            append_back_int_list(neighborList, neighbor);
        }
    }

    return neighborList;

}


