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

IntList * new_int_list();

IntListObject * new_int_list_object(int x);

void append_back_int_list(IntList *list, int x);

int pop_back_int_list(IntList *list);

void print_int_list(IntList *list);

void append_front_int_list(IntList *list, int x);

int pop_front_int_list(IntList *list);

int in_int_list(IntList *list, int x);

#endif
