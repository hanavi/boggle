#ifndef _LIST_H_
#define _LIST_H_


typedef struct int_list_object
{

    struct int_list_object *next;
    struct int_list_object *prev;
    int x;

} IntListObject;


typedef struct int_list
{

    struct int_list_object *head;
    struct int_list_object *tail;
    int count;

} IntList;

IntList * new_list_list();

IntListObject * new_int_list_object(int x);

void append_back_int_list(IntList *list, int x);

int pop_back_int_list(IntList *list);

void print_int_list(IntList *list);

void append_front_int_list(IntList *list, int x);

int pop_front_int_list(IntList *list);

#endif
