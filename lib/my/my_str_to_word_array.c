/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include "../../include/struct.h"
#include <fcntl.h>
#include <stdlib.h>

int is_charac(char c)
{
    if ((c == 'O') || (c == 'P')
    || (c == 'X') || (c == '#') || (c == ' ')) {
        return (1);
    }
    return (0);
}

int count(donne_t d)
{
    int	a = 0;
    int	b = 0;
    while (d.buffer[a] != '\0') {
        if (d.buffer[a] == '\n') {
            b ++;
        }
        a ++;
    }
    return (b);
}

int len_of_word(donne_t d, int i)
{
    while (d.buffer[i] != '\n') {
        if (is_charac(d.buffer[i]) != 1)
            return (i);
        i++;
    }
    return (i);
}

donne_t my_str_to_word_array(donne_t d)
{
    int	y = count(d);
    d.buffer2 = malloc(sizeof(char*) * y + 1);
    int	a = 0;
    int	b = 0;
    int	c = 0;
    while (b < y) {
        c = 0;
        d.buffer2[b] = malloc(sizeof (char) * len_of_word(d, a) + 1);
        while (d.buffer[a] != '\0' && is_charac(d.buffer[a]) != 0) {
            d.buffer2[b][c] = d.buffer[a];
            c ++;
            a ++;
        }
        d.buffer2[b][c] = '\0';
        a ++;
        b ++;
    }
    return (d);
}

donne_t my_str_to_word_array1(donne_t d)
{
    int	y = count(d);
    d.bufferRef = malloc(sizeof(char*) * y + 1);
    int	a = 0;
    int	b = 0;
    int	c = 0;
    while (b < y) {
        c = 0;
        d.bufferRef[b] = malloc(sizeof (char) * len_of_word(d, a) + 1);
        while (d.buffer[a] != '\0' && is_charac(d.buffer[a]) != 0) {
            d.bufferRef[b][c] = d.buffer[a];
            c ++;
            a ++;
        }
        d.bufferRef[b][c] = '\0';
        a ++;
        b ++;
    }
    return (d);
}
