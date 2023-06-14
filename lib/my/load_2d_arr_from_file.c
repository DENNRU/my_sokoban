/*
** EPITECH PROJECT, 2022
** load_2d_arr_from_file.c
** File description:
** load_2d_arr_from_file
*/

#include "../../include/my.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char** arr = malloc(sizeof(char*) * (nb_rows + 1));
    for (int i = 0; i <= nb_cols; i++) {
        arr[i] = malloc(sizeof(char) * (nb_cols + 1));
    }
    return (arr);
}

char *read_strpath(char const *filepath, int nb_rows, int nb_cols)
{
    struct stat buf;
    stat(filepath, &buf);
    char *buffer = malloc(sizeof(char) * (buf.st_size + 1));
    int filedes = open(filepath, O_RDONLY);
    int fd = read(filedes, buffer, buf.st_size);
    close(filedes);
    buffer[fd] = '\0';
    return (buffer);
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    char *buffer = read_strpath(filepath, nb_rows, nb_cols);
    int i, j, ij = 0;
    char **buffer2 = mem_alloc_2d_array(nb_rows, nb_cols);
    while (buffer[ij] != '\0') {
        j = 0;
        while (buffer[ij] != '\n' && buffer[ij] != '\0') {
            buffer2[i][j] = buffer[ij];
            j++;
            ij++;
        } j++;
        ij++;
        buffer2[i][j] = '\0';
        i++;
    } buffer2[nb_rows + 1] = NULL;
    return (buffer2);
}
