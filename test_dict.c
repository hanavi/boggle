#include <stdio.h>

#include "dict.h"
#include "board.h"
#include "lists.h"



void test_string()
{
    int i;
    char board[25];

    // Fill the board with a-y
    for (i = 0; i < 24; ++i)
    {
        board[i] = i + 97;
    }

    int status = 0;


    // Load the dictionary
    Letters *dict;
    dict = newLetters();
    load_dictionary(dict);

    IntList* path = new_int_list();

    append_back_int_list(path, (char) 't' - 97);
    print_int_list(path);
    status = check_path_letters(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'r' - 97);
    print_int_list(path);
    status = check_path_letters(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'e' - 97);
    print_int_list(path);
    status = check_path_letters(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'e' - 97);
    print_int_list(path);
    status = check_path_letters(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 's' - 97);
    print_int_list(path);
    status = check_path_letters(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'i' - 97);
    print_int_list(path);
    status = check_path_letters(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'n' - 97);
    print_int_list(path);
    status = check_path_letters(dict, board, path);
    printf("%d\n", status);

    append_back_int_list(path, (char) 'g' - 97);
    print_int_list(path);
    status = check_path_letters(dict, board, path);
    printf("%d\n", status);

    clean_up_dict(dict);
    clean_up_int_list(path);

}


int main(int argc, char *argv[])
{
    test_string();
    return 0;
}
