/*
** EPITECH PROJECT, 2022
** load_file_in_mem.c
** File description:
** load_file_in_mem
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

char *load_file_in_mem(char const *av)
{
    struct stat buf;
    stat(av, &buf);
    int i = 0;
    char *buffer2;
    int filedes = open(av, O_RDONLY);
    char *buffer = malloc(sizeof(char) * (buf.st_size + 1));
    int fd = read(filedes, buffer, buf.st_size);
    buffer[fd] = '\0';
    close(filedes);
    return (buffer);
}
