#ifndef _LIST_H_
#define _LIST_H_


/* Integer linked list object */
typedef struct int_list_object
{

    // The next and previous entries in our linked list
    struct int_list_object *next;
    struct int_list_object *prev;

    // The value we actually care about
    int x;

} IntListObject;


/* Wrapper for a linked list of integer list objects */
typedef struct int_list
{

    // the first and last entries in our linked list
    struct int_list_object *head;
    struct int_list_object *tail;

    // Keep track of the number of entries in the list
    int count;

} IntList;

/* Word linked list object */
typedef struct word_list_object
{

    // The next and previous entries in our linked list
    struct word_list_object *next;
    struct word_list_object *prev;

    // The value we actually care about
    char *str;

} WordListObject;


/* Wrapper for a linked list of word list objects */
typedef struct word_list
{

    // the first and last entries in our linked list
    struct word_list_object *head;
    struct word_list_object *tail;

    // Keep track of the number of entries in the list
    int count;

} WordList;

IntList * new_int_list();

IntListObject * new_int_list_object(int x);

void append_back_int_list(IntList *list, int x);

int pop_back_int_list(IntList *list);

void print_int_list(IntList *list);

void append_front_int_list(IntList *list, int x);

int pop_front_int_list(IntList *list);

int in_int_list(IntList *list, int x);

WordList * new_word_list();

WordListObject * new_word_list_object(char* str);

void print_word_list(WordList *list);

void append_front_word_list(WordList *list, char *str);

void append_back_word_list(WordList *list, char* str);

char *pop_back_word_list(WordList *list);

char *pop_front_word_list(WordList *list);


#endif
