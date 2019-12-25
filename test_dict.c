#include <stdio.h>

#include "dict.h"
#include "board.h"
#include "list.h"



void test_string()
{
    int i;
    // char *board = generate_random_boggle_board();
    char board[25];
    for (i = 0; i < 24; ++i)
    {
        board[i] = i;
    }

    int status = 0;


    // Load the dictionary
    Letters *dict;
    dict = newLetters();
    load_dictionary(dict);

    IntList* path = new_int_list();

    append_back_int_list(path, (char) 't' - 97);
    print_int_list(path);
    status = check_path(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'r' - 97);
    print_int_list(path);
    status = check_path(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'e' - 97);
    print_int_list(path);
    status = check_path(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'e' - 97);
    print_int_list(path);
    status = check_path(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 's' - 97);
    print_int_list(path);
    status = check_path(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'i' - 97);
    print_int_list(path);
    status = check_path(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'n' - 97);
    print_int_list(path);
    status = check_path(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'g' - 97);
    print_int_list(path);
    status = check_path(dict, board, path);
    printf("%d\n", status);

}


int main(int argc, char *argv[])
{
    test_string();
    return 0;
}
