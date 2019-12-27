#include <stdio.h>
#include <stdlib.h>

#include "lists.h"
#include "solve.h"
#include "dict.h"
#include "board.h"


void check_path(Letters *dict, char *board, IntList * path, int n, WordList *words)
{
    int status = 0;
    append_back_int_list(path, n);

    status = check_path_letters(dict, board, path);

    if (status == -1)
    {
        pop_back_int_list(path);
        return;
    }

    if (status == 1)
        append_back_word_list(words, get_word_from_path(path, board));

    IntList *neighbors;
    IntListObject *step;

    neighbors = get_neighbors(n, path);

    if (neighbors->count < 1)
    {
        pop_back_int_list(path);
        return;
    }

    step = neighbors->head;

    while(step)
    {
        check_path(dict, board, path, step->x, words);
        step = step->next;
    }

    pop_back_int_list(path);
}

void solve_boggle_board(char *board, Letters *dict, WordList *words)
{
    int i;
    IntList *path;

    path = new_int_list();

    for(i = 0; i < SIZE*SIZE; ++i)
    {
        path = new_int_list();
        check_path(dict, board, path, i, words);
        free(path);
    }
}



