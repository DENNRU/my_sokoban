/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
    return;
}
