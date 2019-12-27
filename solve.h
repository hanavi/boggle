#ifndef _SOLVE_H_
#define _SOLVE_H_

#include "lists.h"
#include "dict.h"
#include "board.h"

int check_path_letters(Letters *dict, char *board, IntList *path);
void solve_boggle_board(char *board, Letters *dict, WordList *words);



#endif
