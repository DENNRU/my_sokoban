/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "include/my.h"
#include "include/struct.h"
#include <ncurses.h>

donne_t get_end(donne_t d);
donne_t cs_love(donne_t d, char const **av);
donne_t erreur(donne_t d);
int pr_char(donne_t d);
donne_t initialiser(donne_t d);
donne_t move_down(donne_t d);
donne_t move_left(donne_t d);
donne_t move_right(donne_t d);
donne_t move_up(donne_t d);
donne_t get_info(int i, int j, donne_t d);

donne_t scan_info(donne_t d)
{
    int i = 0;
    while (d.bufferRef[i] != NULL) {
        int j = 0;
        while (d.bufferRef[i][j] != '\0') {
            d = get_info(i, j, d);
            j++;
        }
        i++;
    }
    return (d);
}

donne_t the_start(int ac, char const **av)
{
    donne_t d;
    d = cs_love(d, av);
    if (d.valuer == 84)
        return (d);
    while (d.fin == 2) {
        d.ch = getch ();
        if (d.ch == 32) {
            d = my_str_to_word_array(d);
            d = cs_love(d, av);
        } if (d.ch == KEY_UP)
            d = move_up(d);
        if (d.ch == KEY_DOWN)
            d = move_down(d);
        if (d.ch == KEY_LEFT)
            d = move_left(d);
        if (d.ch == KEY_RIGHT)
            d = move_right(d);
        d = get_end(d);
    } endwin ();
    return (d);
}

int app_usage(void)
{
    my_putstr("USAGE\n     ./my_sokoban\nDESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map");
    my_putstr(", containing ‘#’ for walls,\n          ‘P’");
    my_putstr(" for the player, ‘X’ for boxes and");
    my_putstr(" ‘O’ for storage locations.\n");
    return (0);
}

int test_usage(int ac, char const **av)
{
    for (int indice = 1; indice < ac; indice++) {
        if (av[indice][1] == 'h') {
            app_usage();
            return (0);
        }
    }
    donne_t d;
    d = the_start(ac, av);
    if (d.valuer == 84) {
        return (84);
    } if (d.fin == 1) {
        return (1);
    } if (d.fin == 0) {
        return (0);
    }
}

int main(int ac, char const **av)
{
    int indice = 0;
    if (ac < 2 || ac > 2)
        return (84);
    if (ac == 2)
        indice = test_usage(ac, av);
    return (indice);
}
