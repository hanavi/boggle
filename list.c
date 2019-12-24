#include "list.h"
#include <stdio.h>
#include <stdlib.h>

IntList * new_list_list(int x)
{
    IntList *tmpList = (IntList *) malloc(sizeof(IntList));
    tmpList->head = new_int_list_object(x);
    tmpList->tail = tmpList->head;
    tmpList->count = 0;

    return tmpList;
}

IntListObject * new_int_list_object(int x)
{

    IntListObject *tmpListObject = (IntListObject *) malloc(sizeof(IntListObject));

    tmpListObject->next = NULL;
    tmpListObject->prev = NULL;
    tmpListObject->x = x;

    return tmpListObject;

}

void print_int_list(IntList *list)
{
    int i = 0;
    IntListObject *step;
    step = list->head;

    while(step)
    {
        printf("%d ", step->x);
        step = step->next;
    }
    printf("\n");

}

void append_front_int_list(IntList *list, int x)
{
    IntListObject *head;
    IntListObject *newItem;

    head = list->head;

    newItem = new_int_list_object(x);

    head->prev = newItem;
    newItem->next = head;
    list->head = newItem;
    list->count += 1;

}

void append_back_int_list(IntList *list, int x)
{
    IntListObject *tail;
    IntListObject *newItem;

    tail = list->tail;

    newItem = new_int_list_object(x);

    tail->next = newItem;
    newItem->prev = tail;
    list->tail = newItem;
    list->count += 1;

}

int pop_back_int_list(IntList *list)
{
    IntListObject *prev;
    IntListObject *tail;

    tail = list->tail;
    prev = tail->prev;

    list->tail = prev;
    int retInt = tail->x;
    free(tail);

    list->count -= 1;

    if (list->count == 0)
        list->head = NULL;

    return retInt;
}

int pop_front_int_list(IntList *list)
{
    IntListObject *next;
    IntListObject *head;

    head = list->head;
    next = head->next;

    list->head = next;
    int retInt = head->x;
    free(head);

    list->count -= 1;

    if (list->count == 0)
        list->tail = NULL;

    return retInt;
}
