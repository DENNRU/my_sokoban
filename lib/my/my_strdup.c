/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;
    char i;
    char j = (my_strlen(src) + 1);
    str = malloc(j);
    while (i < j) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
