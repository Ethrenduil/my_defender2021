/*
** EPITECH PROJECT, 2021
** draw2.c
** File description:
** draw2
*/

#include "../includes/my.h"

void draw_escape(game_t *game, escape_t *escape)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            user_input_escape(game, escape, game->event);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, escape->bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, escape->b1->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, escape->b2->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, escape->b3->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void draw_tower(game_t *game, tower_t *tower)
{
    sfRenderWindow_drawSprite(game->window, tower->img->sprite, NULL);
}