/*
** EPITECH PROJECT, 2022
** codingstyle1.c
** File description:
** codingstyle1
*/

#include "include/my.h"
#include "include/struct.h"
#include <ncurses.h>

int pr_char(donne_t d);
donne_t initialiser(donne_t d);
donne_t scan_info(donne_t d);
donne_t search_x(int i, int j, donne_t d);

donne_t search(donne_t d)
{
    int i = 0;
    while (d.buffer2[i] != NULL) {
        int j = 0;
        while (d.buffer2[i][j] != '\0') {
            d = search_x(i, j, d);
            j++;
        }
        i++;
    }
    return (d);
}

donne_t initialiser(donne_t d)
{
    d.ch = 0;
    d.i = 0;
    d.j = 0;
    d.box = 0;
    d.o = 0;
    d.O = 0;
    d.X = 0;
    d.p = 0;
    d.erreur = 0;
    d.valuer = 0;
    d.lockxy = 0;
    d.lockx = 0;
    d.fin = 2;
    return (d);
}

int pr_char(donne_t d)
{
    clear();
    refresh ();
    int i = 0;
    while (d.buffer2[i] != NULL) {
        printw(d.buffer2[i]);
        printw("\n");
        i++;
    }
    return (0);
}

donne_t erreur(donne_t d)
{
    if (d.O != d.X)
        d.erreur++;
    if (d.p != 1)
        d.erreur++;
    if (d.erreur != 0)
        return (d);
    return (d);
}

donne_t cs_love(donne_t d, char const **av)
{
    d.buffer = load_file_in_mem(av[1]);
    d = my_str_to_word_array(d);
    d = my_str_to_word_array1(d);
    d = initialiser(d);
    d = scan_info(d);
    d = erreur(d);
    if (d.erreur != 0) {
        d.valuer = 84;
        return (d);
    }
    initscr ();
    keypad (stdscr, TRUE);
    noecho();
    pr_char(d);
    return (d);
}
