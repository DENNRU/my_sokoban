/*
** EPITECH PROJECT, 2022
** is_square_of_size.c
** File description:
** is_square_of_size
*/

#include "../../include/my.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);

int check(char **map, int a, int b)
{
    if (map[a][b] != 'o')
        return (0);
    return (1);
}

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int a, b, re = 0;
    int rx = row + square_size;
    int cx = col + square_size;
    int check_ret = 0;
    a = row;
    for (a; a <= rx - 1; a++) {
        b = col;
        while (b < cx && check_ret != 1) {
            check_ret = check(map, a, b);
            b++;
        }
    }
    return (check_ret);
}
