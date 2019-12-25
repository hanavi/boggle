#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/* Create a new integer list */
IntList * new_int_list()
{
    IntList *tmpList = (IntList *) malloc(sizeof(IntList));
    tmpList->head = NULL;
    tmpList->tail = NULL;
    tmpList->count = 0;

    return tmpList;
}

/* Create a new integer list object */
IntListObject * new_int_list_object(int x)
{

    IntListObject *tmpListObject = (IntListObject *) malloc(sizeof(IntListObject));

    // Set the default values
    tmpListObject->next = NULL;
    tmpListObject->prev = NULL;
    tmpListObject->x = x;

    return tmpListObject;

}

/* Print out the list */
void print_int_list(IntList *list)
{

    int i = 0;
    IntListObject *step;
    step = list->head;

    // Loop through the objects in the list
    while(step)
    {
        printf("%d ", step->x);
        step = step->next;
    }
    printf("\n");

}

/* Append a new integer list object to the front of the integer list */
void append_front_int_list(IntList *list, int x)
{

    IntListObject *head;
    IntListObject *newItem;

    newItem = new_int_list_object(x);

    // If the list already has at least one entry
    if (list->head)
    {
        head = list->head;
        head->prev = newItem;
        newItem->next = head;
    }
    // If the list is emtpy
    else
    {
        list->tail = newItem;
    }

    list->head = newItem;
    list->count += 1;

}

/* Append a new intger list object to the back of the list */
void append_back_int_list(IntList *list, int x)
{

    IntListObject *tail;
    IntListObject *newItem;

    newItem = new_int_list_object(x);

    // If the list is not empty
    if (list->tail)
    {
        tail = list->tail;
        tail->next = newItem;
        newItem->prev = tail;
    }
    // If the list is empty
    else
    {
        list->head = newItem;
    }

    list->tail = newItem;
    list->count += 1;

}

/* Remove the last entry from the back of the list and return the integer value */
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

    // If we remove the last object from the list, fix the head pointer as well
    if (list->count == 0)
        list->head = NULL;

    return retInt;
}

/* Remove the last entry from the front of the list and return the integer value */
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

    // If we remove the last object from the list, fix the tail pointer as well
    if (list->count == 0)
        list->tail = NULL;

    return retInt;
}

/* Check to see if a given integer is in our list */
int in_int_list(IntList *list, int x)
{
    IntListObject *step;
    step = list->head;

    while(step)
    {
        // Return 1 if we find the integer
        if (step->x == x)
            return 1;
        step = step->next;
    }
    // Return 0 since we got to the end and didn't find the integer
    return 0;
}

/* Create a new word list */
WordList * new_word_list()
{
    WordList *tmpList = (WordList *) malloc(sizeof(WordList));

    tmpList->head = NULL;
    tmpList->tail = NULL;
    tmpList->count = 0;

    return tmpList;
}

/* Create a new integer list object */
WordListObject * new_word_list_object(char* str)
{

    WordListObject *tmpListObject = (WordListObject *) malloc(sizeof(WordListObject));

    // Set the default values
    tmpListObject->next = NULL;
    tmpListObject->prev = NULL;

    tmpListObject->str = str;

    return tmpListObject;

}

/* Print out the list */
void print_word_list(WordList *list)
{

    int i = 0;
    WordListObject *step;
    step = list->head;

    // Loop through the objects in the list
    while(step)
    {
        printf("%s\n", step->str);
        step = step->next;
    }

}

/* Append a new integer list object to the front of the integer list */
void append_front_word_list(WordList *list, char *str)
{

    WordListObject *head;
    WordListObject *newItem;

    newItem = new_word_list_object(str);

    // If the list already has at least one entry
    if (list->head)
    {
        head = list->head;
        head->prev = newItem;
        newItem->next = head;
    }
    // If the list is emtpy
    else
    {
        list->tail = newItem;
    }

    list->head = newItem;
    list->count += 1;

}

/* Append a new intger list object to the back of the list */
void append_back_word_list(WordList *list, char* str)
{

    WordListObject *tail;
    WordListObject *newItem;

    newItem = new_word_list_object(str);

    // If the list is not empty
    if (list->tail)
    {
        tail = list->tail;
        tail->next = newItem;
        newItem->prev = tail;
    }
    // If the list is empty
    else
    {
        list->head = newItem;
    }

    list->tail = newItem;
    list->count += 1;

}

/* Remove the last entry from the back of the list and return the integer value */
char *pop_back_word_list(WordList *list)
{

    WordListObject *prev;
    WordListObject *tail;

    tail = list->tail;
    prev = tail->prev;

    list->tail = prev;
    char *retStr = tail->str;
    free(tail);

    list->count -= 1;

    // If we remove the last object from the list, fix the head pointer as well
    if (list->count == 0)
        list->head = NULL;

    return retStr;
}

/* Remove the last entry from the front of the list and return the integer value */
char *pop_front_word_list(WordList *list)
{
    WordListObject *next;
    WordListObject *head;

    head = list->head;
    next = head->next;

    list->head = next;
    char *retStr = head->str;
    free(head);

    list->count -= 1;

    // If we remove the last object from the list, fix the tail pointer as well
    if (list->count == 0)
        list->tail = NULL;

    return retStr;
}
