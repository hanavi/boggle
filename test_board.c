#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "list.h"


int main()
{
    char * board = generate_random_boggle_board();
    char c;
    int n;

    char buf[8];

    print_boggle_board_numbers(board);

    IntList *ignore = new_int_list();
    IntList *neighbors = get_neighbors(0, ignore);

    append_back_int_list(ignore,5);
    append_back_int_list(ignore,2);

    while(1)
    {
        printf("position: ");
        fgets(buf,8,stdin);
        n = atoi(buf);
        neighbors = get_neighbors(n, ignore);
        printf("neighbors: ");
        print_int_list(neighbors);
        free(neighbors);
    }

}
