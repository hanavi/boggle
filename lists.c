#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lists.h"

/* Create a new integer list */
IntList * new_int_list()
{
    IntList *tmpList = malloc(sizeof(IntList));
    tmpList->head = NULL;
    tmpList->tail = NULL;
    tmpList->count = 0;

    return tmpList;
}

/* Create a new integer list object */
IntListObject * new_int_list_object(int x)
{

    IntListObject *tmpListObject = malloc(sizeof(IntListObject));

    // Set the default values
    tmpListObject->next = NULL;
    tmpListObject->prev = NULL;
    tmpListObject->x = x;

    return tmpListObject;

}

/* Print out the list */
void print_int_list(IntList *list)
{

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

void clean_up_int_list(IntList *list)
{
    if (!list)
        return;

    IntListObject * step = list->head;

    while(step)
    {
        step = step->next;
        pop_front_int_list(list);
    }
    free(list);
}

/* Create a new word list */
WordList * new_word_list()
{
    WordList *tmpList = malloc(sizeof(WordList));

    tmpList->head = NULL;
    tmpList->tail = NULL;
    tmpList->count = 0;

    return tmpList;
}

/* Create a new integer list object */
WordListObject * new_word_list_object(char* str)
{

    WordListObject *tmpListObject = malloc(sizeof(WordListObject));

    // Set the default values
    tmpListObject->next = NULL;
    tmpListObject->prev = NULL;

    tmpListObject->str = str;

    return tmpListObject;

}

/* Print out the list */
void print_word_list(WordList *list)
{

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


void insert_alphabetical_word_list(WordList *list, char* str)
{

    WordListObject *step;
    WordListObject *newItem;
    WordListObject *lastItem;

    int i = 0;
    char n,c;
    int cLength = 0;
    int nLength = 0;
    int maxLen = 0;


    list->count += 1;

    newItem = new_word_list_object(str);

    // If the list is empty
    if (!list->tail)
    {
        list->head = newItem;
        list->tail = newItem;
        return;
    }

    // If the list is not empty
    step = list->head;
    lastItem = list->head;

    cLength = strlen(str);

    int cont = 0;

    while (step)
    {
        cont = 0;
        nLength = strlen(step->str);
        maxLen = nLength > cLength ? cLength : nLength;

        for ( i = 0; i < maxLen ; i++)
        {
            c = newItem->str[i];
            n = step->str[i];

            // if the current word comes before the next word in the list
            if (c < n)
            {
                if (step == list->head)
                {
                    list->head = newItem;
                    newItem->next = step;
                }
                else
                {
                    newItem->next = step;
                    lastItem->next = newItem;
                    newItem->prev = lastItem;
                }
                return;
            }
            else if (c > n)
            {
                lastItem = step;
                step = step->next;
                cont = 1;
                break;
            }

        }
        if (cont == 1)
        {
            continue;
        }

        if (nLength == cLength)
        {
            if (step == list->head)
            {
                list->head = newItem;
                newItem->next = step;
            }
            else
            {
                newItem->next = step;
                lastItem->next = newItem;
                newItem->prev = lastItem;
            }
            return;
        }

        lastItem = step;
        step = step->next;
    }

    lastItem->next = newItem;
    newItem->prev = lastItem;
    list->tail = newItem;
}

void clean_up_word_list(WordList *list)
{
    if (!list)
        return;

    WordListObject * step = list->head;

    while(step)
    {
        step = step->next;
        pop_front_word_list(list);
    }
    free(list);
}
