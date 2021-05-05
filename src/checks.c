/*
** EPITECH PROJECT, 2021
** checks.c
** File description:
** Checking functions
*/

#include "../includes/my.h"

int check_lost(game_t *game)
{
    if (game->hp > 0)
        return 0;
    return 1;
}

void check_go(game_t *game)
{
    sfClock_restart(game->clock);
    for (int i = 0 ; i < game->cnb; i++) {
        if (game->e[i].alive == 1) {
            sfClock_restart(game->e[i].mclock);
            sfClock_restart(game->e[i].aclock);
        }
    }
}