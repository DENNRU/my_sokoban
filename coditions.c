/*
** EPITECH PROJECT, 2022
** conditions.c
** File description:
** coditions
*/

#include "include/my.h"
#include "include/struct.h"
#include <ncurses.h>

donne_t search_x(int i, int j, donne_t d)
{
    if (d.buffer2[i][j] == 'X') {
        if ((d.buffer2[i - 1][j] == '#' || d.buffer2[i - 1][j] == 'X')
            && (d.buffer2[i][j - 1] == '#' || d.buffer2[i][j - 1] == 'X'))
                d.lockxy++;
        if ((d.buffer2[i - 1][j] == '#' || d.buffer2[i - 1][j] == 'X')
            && (d.buffer2[i][j + 1] == '#' || d.buffer2[i][j + 1] == 'X'))
                d.lockxy++;
        if ((d.buffer2[i + 1][j] == '#' || d.buffer2[i + 1][j] == 'X')
            && (d.buffer2[i][j + 1] == '#' || d.buffer2[i][j + 1] == 'X'))
                d.lockxy++;
        if ((d.buffer2[i + 1][j] == '#' || d.buffer2[i + 1][j] == 'X')
            && (d.buffer2[i][j - 1] == '#' || d.buffer2[i][j - 1] == 'X'))
                d.lockxy++;
    }
    if (d.lockxy >= 1)
        d.lockx++;
    d.lockxy = 0;
    return (d);
}

donne_t get_refresh(int i, int j, donne_t d)
{
    if (d.buffer2[i][j] == 'O')
        d.o++;
    return (d);
}

donne_t refresh_map(donne_t d)
{
    int i = 0;
    while (d.buffer2[i] != NULL) {
        int j = 0;
        while (d.buffer2[i][j] != '\0') {
            d = get_refresh(i, j, d);
            j++;
        }
        i++;
    }
    return (d);
}
