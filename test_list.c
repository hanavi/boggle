#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void test_word_list()
{
    WordList *list = new_word_list();

    append_back_word_list(list, "this");
    append_back_word_list(list, "is");
    append_back_word_list(list, "the");
    append_back_word_list(list, "beginning");

    append_front_word_list(list, "this");
    append_front_word_list(list, "is");
    append_front_word_list(list, "the");
    append_front_word_list(list, "beginning");

    print_word_list(list);

}

/* Check some int list functions */
void test_int_list()
{

    int i = 0;  // iterator

    // Test one
    printf("List Test: append back pop back\n");
    IntList *list = new_int_list();
    for (i = 0; i < 10; ++i)
    {
        append_back_int_list(list, i+1);
    }
    print_int_list(list);

    while(list->count > 0)
    {
        int x = pop_back_int_list(list);
        printf("%d ", x);
    }

    printf("\n");
    printf("head: %d\n", list->head);
    printf("tail: %d\n", list->tail);
    printf("\n\n");
    free(list);

    // Test two
    printf("List Test: append front pop back\n");
    list = new_int_list();
    for (i = 0; i < 10; ++i)
    {
        append_front_int_list(list, i+1);
    }
    print_int_list(list);

    while(list->count > 0)
    {
        int x = pop_back_int_list(list);
        printf("%d ", x);
    }
    printf("\n");
    printf("head: %d\n", list->head);
    printf("tail: %d\n", list->tail);
    printf("\n\n");
    free(list);

    // Test three
    printf("List Test: append front pop front\n");
    list = new_int_list();
    for (i = 0; i < 10; ++i)
    {
        append_front_int_list(list, i+1);
    }
    print_int_list(list);

    while(list->count > 0)
    {
        int x = pop_front_int_list(list);
        printf("%d ", x);
    }
    printf("\n");
    printf("head: %d\n", list->head);
    printf("tail: %d\n", list->tail);
    printf("\n\n");
    free(list);

    // Test four
    printf("List Test: append back pop front\n");
    list = new_int_list();
    for (i = 0; i < 10; ++i)
    {
        append_back_int_list(list, i+1);
    }
    print_int_list(list);

    while(list->count > 0)
    {
        int x = pop_front_int_list(list);
        printf("%d ", x);
    }
    printf("\n");
    printf("head: %d\n", list->head);
    printf("tail: %d\n", list->tail);
    printf("\n\n");
    free(list);

}


int main(int argc, char *argv[])
{

    // test_int_list();
    test_word_list();

    return 0;
}
