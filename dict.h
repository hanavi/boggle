
#ifndef DICT_H_
#define DICT_H_

#include "list.h"

/* This struct is the foundation of our trie */
typedef struct letters {

    // hold all the letters
    struct letters *letters[26];

    // set if end of word
    int end_of_word;

} Letters;

Letters * newLetters();

void strip_newline(char *string);

int check_string_lower(char *string);

void add_word(Letters *dict, char *buf);

void load_dictionary(Letters *dict);

int find_word(Letters *dict, char *word);

int check_path(Letters *dict, char *board, IntList *path);

#endif
