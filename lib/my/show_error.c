/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** quentin.vandersteene@epitech.eu
*/

#include "../../includes/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int show_error_file(char const *str, int fd)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_puterror(str[i]);
    my_puterror('\n');
    close(fd);
    return 1;
}

int show_error(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_puterror(str[i]);
    my_puterror('\n');
    return 84;
}
