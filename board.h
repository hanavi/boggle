#ifndef BOARD_H_
#define BOARD_H_

#include "lists.h"

// For now we have a fixed 5x5 grid board (maybe this will become dynamic?)
#define SIZE 5

char * generate_random_boggle_board();

void print_boggle_board(char *board);

void print_boggle_board_numbers(char *board);

IntList *get_neighbors(int n, IntList* ignore);


#endif
