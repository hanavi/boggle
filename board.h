#ifndef BOARD_H_
#define BOARD_H_

#include "list.h"

char * generate_random_boggle_board();

void print_boggle_board(char *board);

void print_boggle_board_numbers(char *board);

IntList *get_neighbors(int n, IntList* ignore);


#endif
