#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "main.h"
#include "dict.h"
#include "lists.h"
#include "solve.h"
#include "board.h"


void run_check(int argc, char *argv[])
{
    char buf[80];  // For storing the word to be checked

    // Load the dictionary
    Letters *dict;
    dict = newLetters();
    load_dictionary(dict);

    // If we don't pass a word as an argument, ask for one
    if (argc == 1)
    {
        printf("Enter a word: ");
        fgets(buf, 80, stdin);
        strip_newline(buf);
    }
    else
    {
        // Parse the word passed as an argument
        int bufsize = strlen(argv[1]);
        bufsize = bufsize < 80 ? bufsize : 79;
        strncpy(buf, argv[1], bufsize);
        buf[bufsize] = '\0';

    }

    // See if the word is in the dict and output appropriately
    if (find_word(dict, buf) == 1)
        printf("%s is a word!\n",buf);
    else
        printf("%s is NOT a word!\n",buf);

}


int main(int argc, char *argv[])
{

    // Load the dictionary
    Letters *dict;
    dict = newLetters();
    load_dictionary(dict);

    char *boggleBoard = generate_random_boggle_board();

    WordList *words = new_word_list();

    solve_boggle_board(boggleBoard, dict, words);

    print_boggle_board(boggleBoard);
    // print_word_list(words);
    printf("Found %d words\n", words->count);



    gtk_init(&argc, &argv);

    GtkBuilder* builder;
    GError *error = NULL;

    builder = gtk_builder_new();
    if(gtk_builder_add_from_file(builder, "boggle_main.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
        return 1;
    }


    GObject *window = gtk_builder_get_object(builder, "window");


    GObject *label0 = gtk_builder_get_object(builder, "entry_0");
    GObject *label1 = gtk_builder_get_object(builder, "entry_1");
    GObject *label2 = gtk_builder_get_object(builder, "entry_2");
    GObject *label3 = gtk_builder_get_object(builder, "entry_3");
    GObject *label4 = gtk_builder_get_object(builder, "entry_4");
    GObject *label5 = gtk_builder_get_object(builder, "entry_5");
    GObject *label6 = gtk_builder_get_object(builder, "entry_6");
    GObject *label7 = gtk_builder_get_object(builder, "entry_7");
    GObject *label8 = gtk_builder_get_object(builder, "entry_8");
    GObject *label9 = gtk_builder_get_object(builder, "entry_9");
    GObject *label10 = gtk_builder_get_object(builder, "entry_10");
    GObject *label11 = gtk_builder_get_object(builder, "entry_11");
    GObject *label12 = gtk_builder_get_object(builder, "entry_12");
    GObject *label13 = gtk_builder_get_object(builder, "entry_13");
    GObject *label14 = gtk_builder_get_object(builder, "entry_14");
    GObject *label15 = gtk_builder_get_object(builder, "entry_15");
    GObject *label16 = gtk_builder_get_object(builder, "entry_16");
    GObject *label17 = gtk_builder_get_object(builder, "entry_17");
    GObject *label18 = gtk_builder_get_object(builder, "entry_18");
    GObject *label19 = gtk_builder_get_object(builder, "entry_19");
    GObject *label20 = gtk_builder_get_object(builder, "entry_20");
    GObject *label21 = gtk_builder_get_object(builder, "entry_21");
    GObject *label22 = gtk_builder_get_object(builder, "entry_22");
    GObject *label23 = gtk_builder_get_object(builder, "entry_23");
    GObject *label24 = gtk_builder_get_object(builder, "entry_24");

    GObject *wordlist = gtk_builder_get_object(builder, "wordlist");

    GObject *menu_item_quit = gtk_builder_get_object(builder, "menu_item_quit");
    g_signal_connect(G_OBJECT(menu_item_quit), "activate",G_CALLBACK(gtk_main_quit), NULL);


    char ll_0[8];
    char ll_1[8];
    char ll_2[8];
    char ll_3[8];
    char ll_4[8];
    char ll_5[8];
    char ll_6[8];
    char ll_7[8];
    char ll_8[8];
    char ll_9[8];
    char ll_10[8];
    char ll_11[8];
    char ll_12[8];
    char ll_13[8];
    char ll_14[8];
    char ll_15[8];
    char ll_16[8];
    char ll_17[8];
    char ll_18[8];
    char ll_19[8];
    char ll_20[8];
    char ll_21[8];
    char ll_22[8];
    char ll_23[8];
    char ll_24[8];

    sprintf(ll_0, "%c", boggleBoard[0]);
    sprintf(ll_1, "%c", boggleBoard[1]);
    sprintf(ll_2, "%c", boggleBoard[2]);
    sprintf(ll_3, "%c", boggleBoard[3]);
    sprintf(ll_4, "%c", boggleBoard[4]);
    sprintf(ll_5, "%c", boggleBoard[5]);
    sprintf(ll_6, "%c", boggleBoard[6]);
    sprintf(ll_7, "%c", boggleBoard[7]);
    sprintf(ll_8, "%c", boggleBoard[8]);
    sprintf(ll_9, "%c", boggleBoard[9]);
    sprintf(ll_10, "%c", boggleBoard[10]);
    sprintf(ll_11, "%c", boggleBoard[11]);
    sprintf(ll_12, "%c", boggleBoard[12]);
    sprintf(ll_13, "%c", boggleBoard[13]);
    sprintf(ll_14, "%c", boggleBoard[14]);
    sprintf(ll_15, "%c", boggleBoard[15]);
    sprintf(ll_16, "%c", boggleBoard[16]);
    sprintf(ll_17, "%c", boggleBoard[17]);
    sprintf(ll_18, "%c", boggleBoard[18]);
    sprintf(ll_19, "%c", boggleBoard[19]);
    sprintf(ll_20, "%c", boggleBoard[20]);
    sprintf(ll_21, "%c", boggleBoard[21]);
    sprintf(ll_22, "%c", boggleBoard[22]);
    sprintf(ll_23, "%c", boggleBoard[23]);
    sprintf(ll_24, "%c", boggleBoard[24]);


    gtk_label_set_text(GTK_LABEL(label0), ll_0);
    gtk_label_set_text(GTK_LABEL(label1), ll_1);
    gtk_label_set_text(GTK_LABEL(label2), ll_2);
    gtk_label_set_text(GTK_LABEL(label3), ll_3);
    gtk_label_set_text(GTK_LABEL(label4), ll_4);
    gtk_label_set_text(GTK_LABEL(label5), ll_5);
    gtk_label_set_text(GTK_LABEL(label6), ll_6);
    gtk_label_set_text(GTK_LABEL(label7), ll_7);
    gtk_label_set_text(GTK_LABEL(label8), ll_8);
    gtk_label_set_text(GTK_LABEL(label9), ll_9);
    gtk_label_set_text(GTK_LABEL(label10), ll_10);
    gtk_label_set_text(GTK_LABEL(label11), ll_11);
    gtk_label_set_text(GTK_LABEL(label12), ll_12);
    gtk_label_set_text(GTK_LABEL(label13), ll_13);
    gtk_label_set_text(GTK_LABEL(label14), ll_14);
    gtk_label_set_text(GTK_LABEL(label15), ll_15);
    gtk_label_set_text(GTK_LABEL(label16), ll_16);
    gtk_label_set_text(GTK_LABEL(label17), ll_17);
    gtk_label_set_text(GTK_LABEL(label18), ll_18);
    gtk_label_set_text(GTK_LABEL(label19), ll_19);
    gtk_label_set_text(GTK_LABEL(label20), ll_20);
    gtk_label_set_text(GTK_LABEL(label21), ll_21);
    gtk_label_set_text(GTK_LABEL(label22), ll_22);
    gtk_label_set_text(GTK_LABEL(label23), ll_23);
    gtk_label_set_text(GTK_LABEL(label24), ll_24);

    GtkWidget *wordlist_labels[words->count];
    int i = 0;
    WordListObject *ptr;
    ptr = words->head;
    for (i = 0; i < words->count; ++i)
    {

        wordlist_labels[i] = gtk_label_new(ptr->str);
        ptr = ptr->next;
        gtk_container_add(GTK_CONTAINER(wordlist), wordlist_labels[i]);
        gtk_widget_show(GTK_WIDGET(wordlist_labels[i]));
    }
    ptr = NULL;

    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();

    clean_up_word_list(words);
    clean_up_dict(dict);
    free(boggleBoard);

    return 0;
}
