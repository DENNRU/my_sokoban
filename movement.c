/*
** EPITECH PROJECT, 2022
** movement.c
** File description:
** movement
*/

#include "include/my.h"
#include "include/struct.h"
#include <ncurses.h>

int pr_char(donne_t d);
donne_t boxd(donne_t d);
donne_t boxl(donne_t d);
donne_t boxr(donne_t d);
donne_t boxu(donne_t d);

donne_t get_info(int i, int j, donne_t d)
{
    if (d.bufferRef[i][j] == 'X')
        d.X++;
    if (d.bufferRef[i][j] == 'O')
        d.O++;
    if (d.bufferRef[i][j] == 'P') {
        d.p++;
        d.i = i;
        d.j = j;
    }
    if (d.bufferRef[i][j] != ' ' && d.bufferRef[i][j] != '#' &&
        d.bufferRef[i][j] != 'X' && d.bufferRef[i][j] != 'O' &&
        d.bufferRef[i][j] != 'P') {
            d.erreur++;
    }
    return (d);
}

donne_t move_down(donne_t d)
{
    if (d.buffer2[d.i + 1][d.j] == '#') {
        pr_char(d);
    } else {
        d = boxd(d);
        if (d.box != 0) {
            d.box = 0;
            return (d);
        } if (d.bufferRef[d.i][d.j] == 'O') {
            d.buffer2[d.i][d.j] = 'O';
            d.i++;
            d.buffer2[d.i][d.j] = 'P';
            pr_char(d);
        } else {
            d.buffer2[d.i][d.j] = ' ';
            d.i++;
            d.buffer2[d.i][d.j] = 'P';
            pr_char(d);
        }
    }
    return (d);
}

donne_t move_left(donne_t d)
{
    if (d.buffer2[d.i][d.j - 1] == '#') {
        pr_char(d);
    } else {
        d = boxl(d);
        if (d.box != 0) {
            d.box = 0;
            return (d);
        } if (d.bufferRef[d.i][d.j] == 'O') {
            d.buffer2[d.i][d.j] = 'O';
            d.j--;
            d.buffer2[d.i][d.j] = 'P';
            pr_char(d);
        } else {
            d.buffer2[d.i][d.j] = ' ';
            d.j--;
            d.buffer2[d.i][d.j] = 'P';
            pr_char(d);
        }
    }
    return (d);
}

donne_t move_right(donne_t d)
{
    if (d.buffer2[d.i][d.j + 1] == '#') {
        pr_char(d);
    } else {
        d = boxr(d);
        if (d.box != 0) {
            d.box = 0;
            return (d);
        } if (d.bufferRef[d.i][d.j] == 'O') {
            d.buffer2[d.i][d.j] = 'O';
            d.j++;
            d.buffer2[d.i][d.j] = 'P';
            pr_char(d);
        } else {
            d.buffer2[d.i][d.j] = ' ';
            d.j++;
            d.buffer2[d.i][d.j] = 'P';
            pr_char(d);
        }
    }
    return (d);
}

donne_t move_up(donne_t d)
{
    if (d.buffer2[d.i - 1][d.j] == '#') {
        pr_char(d);
    } else {
        d = boxu(d);
        if (d.box != 0) {
            d.box = 0;
            return (d);
        } if (d.bufferRef[d.i][d.j] == 'O') {
            d.buffer2[d.i][d.j] = 'O';
            d.i--;
            d.buffer2[d.i][d.j] = 'P';
            pr_char(d);
        } else {
            d.buffer2[d.i][d.j] = ' ';
            d.i--;
            d.buffer2[d.i][d.j] = 'P';
            pr_char(d);
        }
    }
    return (d);
}
