/*
** EPITECH PROJECT, 2022
** box-mv.c
** File description:
** box-mv
*/

#include "include/my.h"
#include "include/struct.h"
#include <ncurses.h>

int pr_char(donne_t d);
donne_t search(donne_t d);
donne_t refresh_map(donne_t d);

donne_t get_end(donne_t d)
{
    d.o = 0;
    d = refresh_map(d);
    if (d.o == 0) {
        d.fin = 0;
        return (d);
    }
    d.lockx = 0;
    d = search(d);
    if (d.lockx == d.O) {
        d.fin = 1;
        return (d);
    }
    return (d);
}

donne_t boxd(donne_t d)
{
    if (d.buffer2[d.i + 1][d.j] == 'X') {
        d.box++;
        if (d.buffer2[d.i + 2][d.j] == '#' || d.buffer2[d.i + 2][d.j] == 'X')
            return (d);
        if (d.bufferRef[d.i][d.j] == 'O' && d.buffer2[d.i + 2][d.j] != '#'
            && d.buffer2[d.i + 2][d.j] != 'X') {
            d.buffer2[d.i][d.j] = 'O';
            d.i++;
            d.buffer2[d.i][d.j] = 'P';
            d.buffer2[d.i + 1][d.j] = 'X';
            pr_char(d);
        } else {
            d.buffer2[d.i][d.j] = ' ';
            d.i++;
            d.buffer2[d.i][d.j] = 'P';
            d.buffer2[d.i + 1][d.j] = 'X';
            pr_char(d);
        }
    }
    return (d);
}

donne_t boxl(donne_t d)
{
        if (d.buffer2[d.i][d.j - 1] == 'X') {
        d.box++;
        if (d.buffer2[d.i][d.j - 2] == '#' || d.buffer2[d.i][d.j - 2] == 'X')
            return (d);
        if (d.bufferRef[d.i][d.j] == 'O' && d.buffer2[d.i][d.j - 2] != '#'
            && d.buffer2[d.i][d.j - 2] != 'X') {
            d.buffer2[d.i][d.j] = 'O';
            d.j--;
            d.buffer2[d.i][d.j] = 'P';
            d.buffer2[d.i][d.j - 1] = 'X';
            pr_char(d);
        } else {
            d.buffer2[d.i][d.j] = ' ';
            d.j--;
            d.buffer2[d.i][d.j] = 'P';
            d.buffer2[d.i][d.j - 1] = 'X';
            pr_char(d);
        }
    }
    return (d);
}

donne_t boxr(donne_t d)
{
    if (d.buffer2[d.i][d.j + 1] == 'X') {
        d.box++;
        if (d.buffer2[d.i][d.j + 2] == '#' || d.buffer2[d.i][d.j + 2] == 'X')
            return (d);
        if (d.bufferRef[d.i][d.j] == 'O' && d.buffer2[d.i][d.j + 2] != '#'
            && d.buffer2[d.i][d.j + 2] != 'X') {
            d.buffer2[d.i][d.j] = 'O';
            d.j++;
            d.buffer2[d.i][d.j] = 'P';
            d.buffer2[d.i][d.j + 1] = 'X';
            pr_char(d);
        } else {
            d.buffer2[d.i][d.j] = ' ';
            d.j++;
            d.buffer2[d.i][d.j] = 'P';
            d.buffer2[d.i][d.j + 1] = 'X';
            pr_char(d);
        }
    }
    return (d);
}

donne_t boxu(donne_t d)
{
    if (d.buffer2[d.i - 1][d.j] == 'X') {
        d.box++;
        if (d.buffer2[d.i - 2][d.j] == '#' || d.buffer2[d.i - 2][d.j] == 'X')
            return (d);
        if (d.bufferRef[d.i][d.j] == 'O' && d.buffer2[d.i - 2][d.j] != '#'
            && d.buffer2[d.i - 2][d.j] != 'X') {
            d.buffer2[d.i][d.j] = 'O';
            d.i--;
            d.buffer2[d.i][d.j] = 'P';
            d.buffer2[d.i - 1][d.j] = 'X';
            pr_char(d);
        } else {
            d.buffer2[d.i][d.j] = ' ';
            d.i--;
            d.buffer2[d.i][d.j] = 'P';
            d.buffer2[d.i - 1][d.j] = 'X';
            pr_char(d);
        }
    }
    return (d);
}
