/*
** EPITECH PROJECT, 2021
** free.c
** File description:
** free handling
*/

#include "../includes/my.h"

void free_game(game_t *game)
{
    free(game->menu->p);
    free(game->menu->pr);
    free(game->menu->q);
    free(game->menu);
    free(game->opt->a);
    free(game->opt->c1);
    free(game->opt->one);
    free(game->opt->two);
    free(game->opt->three);
    free(game->opt->i);
    free(game->opt);
    free(game->bg);
    free(game->s);
    free(game->pui);
    free(game);
}

void free_escape(escape_t *escape)
{
    free(escape->b1);
    free(escape->b2);
    free(escape->b3);
    free(escape->bg);
    free(escape);
}