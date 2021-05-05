/*
** EPITECH PROJECT, 2021
** int_tochar.c
** File description:
** int_tochar
*/

#include "../../includes/my.h"

int division_max(int nb)
{
    int i = 0;
    int division = 1;

    for (nb;nb > 0; i++)
        nb /= 10;
    i--;
    for (i;i > 0; i--)
        division *= 10;
    return (division);
}

char *int_tochar2(int division, int nb, int neg)
{
    int temp = 1;
    int i = 0;
    char *str = malloc(sizeof(char) * nb + 2);

    if (neg == 1)
        str[i++] = '-';
    for (i; division >= 1; i++) {
        temp = nb / division;
        nb %= division;
        str[i] = temp + '0';
        division /= 10;
    }
    str[i] = '\0';
    return (str);
}

char *int_tochar(int nb)
{
    int division = 1;
    int neg = 0;
    char *str;

    if (nb < 10 && nb >= 0) {
        str = malloc(sizeof(char) * 2);
        str[0] = nb + '0';
        str[1] = '\0';
        return (str);
    }
    if (nb < 0) {
        neg = 1;
        nb *= - 1;
    }
    division = division_max(nb);
    return (int_tochar2(division, nb, neg));
}
