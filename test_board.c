#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "lists.h"

/* Run a simple check of the neighbors for a given entry */
int check_neighbors()
{
    char * board = generate_random_boggle_board();
    int n;

    char buf[8];

    print_boggle_board_numbers(board);

    IntList *ignore = new_int_list();
    IntList *neighbors; // = get_neighbors(0, ignore);

    // Set a couple of entries to ignore
    append_back_int_list(ignore,5);
    append_back_int_list(ignore,2);

    while(1)
    {
        // Read a position in from input
        printf("position: ");
        fgets(buf,8,stdin);
        n = atoi(buf);

        // Get the neighbors and print them out
        neighbors = get_neighbors(n, ignore);
        printf("neighbors: ");
        print_int_list(neighbors);

        clean_up_int_list(neighbors);
    }

    clean_up_int_list(ignore);
    free(board);
}


int main()
{
    check_neighbors();
}
