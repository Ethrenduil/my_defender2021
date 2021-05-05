/*
** EPITECH PROJECT, 2021
** draw.c
** File description:
** draw window
*/

#include "../includes/my.h"

void draw_menu(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            user_input_menu(game, game->event);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->menu->bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->p->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->pr->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->q->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void draw_option(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            user_input_options(game, game->event);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->opt->bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->opt->c1->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->opt->one->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->opt->two->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->opt->three->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->opt->sound->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->opt->music->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->opt->i->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->opt->a->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void draw_info(game_t *game)
{
    change_texture("materials/info_s.png", game->opt->i);
    game->opt->i->pos = (sfVector2f) {742, 144};
    sfSprite_setPosition(game->opt->i->sprite, game->opt->i->pos);
}

void draw_game(game_t *game, enemy_t *enemy)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)){
        user_input_game(game, game->event);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->s->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->go->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->pui->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->hpt.text, NULL);
    sfRenderWindow_drawText(game->window, game->wavet.text, NULL);
    sfRenderWindow_drawText(game->window, game->wavet2.text, NULL);
    sfRenderWindow_drawText(game->window, game->moneyt.text, NULL);
    sfRenderWindow_drawSprite(game->window, game->base->sprite, NULL);
    draw_all_enemy(game, enemy);
    draw_game2(game);
    sfRenderWindow_display(game->window);
}

void draw_game2(game_t *game)
{
    for (int i = 0; i < 5; i++) {
        draw_tower(game, &game->tower[i]);
    }
}
