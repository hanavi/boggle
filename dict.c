#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"
#include "board.h"


/* Build a new Letter struct and return it */
Letters * newLetters()
{
    int iter = 0;

    Letters *tmpLetters;
    tmpLetters = malloc(sizeof(Letters));

    // Set all the letters to NULL to begein with
    for (iter = 0; iter < 26; ++iter)
    {
        tmpLetters->letters[iter] = NULL;
    }

    // By default this struct does not end a word
    tmpLetters->end_of_word = 0;

    return tmpLetters;
}

/* Assuming the last char before the end null is newline, remove it */
void strip_newline(char *string)
{
    int count = strlen(string);
    string[count-1] = '\0';
}

/* Check to make sure our string only has lowercase letters */
int check_string_lower(char *string)
{
    int iter = 0;
    int count = strlen(string) - 1;

    for (iter = 0; iter < count; ++iter)
    {
        if ((string[iter] < 97) || (string[iter] > 122))
            return 0;
    }

    return 1;

}

/* Add a new word to our dictionary */
void add_word(Letters *dict, char *buf)
{
    int iter = 0;
    int count = strlen(buf);
    int c = 0;
    Letters *step = dict;

    // Add the letters of the words and move down a step as you go
    for (iter = 0; iter < count; ++iter)
    {
        // make sure our letters are between 0 and 25
        c = buf[iter] - 97;

        // add the next level if needed
        if (step->letters[c] == 0)
        {
            step->letters[c] = newLetters();
        }
        step = step->letters[c];
    }

    // Finally set that we have reached the end of a word
    step->end_of_word = 1;
}

/* Build the dictionary based on the built-in linux dict files */
void load_dictionary(Letters *dict)
{
    char buf[80];
    FILE *fd;

    fd = fopen("/usr/share/dict/american-english", "r");
    if (fd == NULL)
    {
        printf("Error loading dictionary file\n");
        exit(1);
    }
    while ( fgets(buf, 80, fd) != NULL )
    {
        // Get rid of any string that isn't made of only lowercase letters
        if (check_string_lower(buf) == 0)
            continue;

        // Get rid of the newline that comes in by default from fgets
        strip_newline(buf);

        // Obviously add the word
        add_word(dict, buf);
    }
}

int check_path_letters(Letters *dict, char *board, IntList *path)
{

    IntListObject *wordStep;
    Letters *dictStep;
    int c;

    dictStep = dict;
    wordStep = path->head;

    while(wordStep)
    {
        c = board[wordStep->x] - 97;
        // c = board[wordStep->x];
        // c = wordStep->x // - 97;

        // return -1 if the string of letters is not in the dictionary
        if (dictStep->letters[c] == NULL)
            return -1;

        dictStep = dictStep->letters[c];
        wordStep = wordStep->next;
    }

    // return 0 if it is a possible string path but the word is too short
    if (path->count < 3)
        return 0;

    // return 1 if we get to the end of a word
    if (dictStep->end_of_word == 1)
        return 1;

    // return 0 if the string exists but is not a full word
    return 0;

}

/* Check to see if a word is in our dictionary */
int find_word(Letters *dict, char *word)
{
    int iter = 0;
    int c;
    Letters *step;
    int count = strlen(word);

    if (count < 3)
        return 0;

    step = dict;

    // Step through the letters and down the trie
    for (iter = 0; iter < count; ++iter)
    {
        c = word[iter] - 97;

        // If we only have a null pointer return false
        if (step->letters[c] == 0)
            return 0;

        step = step->letters[c];
    }

    // If the last character of the string doesn't end a word return false
    if (step->end_of_word == 0)
        return 0;

    // if we get to here, the string should be a word in the dict
    return 1;
}

char *get_word_from_path(IntList* path, char *board)
{
    char *buf;
    int n = 0;
    int i = 0;
    char c = 0;
    int bufSize = path->count + 1;

    buf = malloc(sizeof(char)*bufSize);

    IntListObject *step;
    step = path->head;
    while(step)
    {
        n = step->x;
        c = board[n];
        buf[i] = c;
        step = step->next;
        i += 1;
    }

    buf[i] = '\0';

    return buf;
}

void clean_up_dict(Letters *dict)
{
    int i;
    for (i = 0; i < 26; ++i)
    {
        if(!dict->letters[i])
            continue;
        clean_up_dict(dict->letters[i]);
    }
    free(dict->letters);
}
