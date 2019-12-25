#include "list.h"
#include <stdio.h>
#include <stdlib.h>

IntList * new_int_list()
{
    IntList *tmpList = (IntList *) malloc(sizeof(IntList));
    tmpList->head = NULL;
    tmpList->tail = NULL;
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

    newItem = new_int_list_object(x);

    if (list->head)
    {
        head = list->head;
        head->prev = newItem;
        newItem->next = head;
    }
    else
    {
        list->tail = newItem;
    }

    list->head = newItem;
    list->count += 1;

}

void append_back_int_list(IntList *list, int x)
{
    IntListObject *tail;
    IntListObject *newItem;

    newItem = new_int_list_object(x);

    if (list->tail)
    {
        tail = list->tail;
        tail->next = newItem;
        newItem->prev = tail;
    }
    else
    {
        list->head = newItem;
    }

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

int in_int_list(IntList *list, int x)
{
    IntListObject *step;
    step = list->head;

    while(step)
    {
        if (step->x == x)
            return 1;
        step = step->next;
    }
    return 0;
}
