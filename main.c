#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "dict.h"
#include "lists.h"
#include "solve.h"
#include "board.h"

void run_check(int argc, char *argv[])
{
    int iter = 0;  // For iterating
    char buf[80];  // For storing the word to be checked

    // Load the dictionary
    Letters *dict;
    dict = newLetters();
    load_dictionary(dict);

    // If we don't pass a word as an argument, ask for one
    if (argc == 1)
    {
        printf("Enter a word: ");
        fgets(buf, 80, stdin);
        strip_newline(buf);
    }
    else
    {
        // Parse the word passed as an argument
        int bufsize = strlen(argv[1]);
        bufsize = bufsize < 80 ? bufsize : 79;
        strncpy(buf, argv[1], bufsize);
        buf[bufsize] = '\0';

    }

    // See if the word is in the dict and output appropriately
    if (find_word(dict, buf) == 1)
        printf("%s is a word!\n",buf);
    else
        printf("%s is NOT a word!\n",buf);

}

int main(int argc, char *argv[])
{

    // Load the dictionary
    Letters *dict;
    dict = newLetters();
    load_dictionary(dict);

    char *boggleBoard = generate_random_boggle_board();

    WordList *words = new_word_list();

    solve_boggle_board(boggleBoard, dict, words);

    print_boggle_board(boggleBoard);
    print_word_list(words);

    return 0;
}
