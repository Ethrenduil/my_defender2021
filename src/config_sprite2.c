/*
** EPITECH PROJECT, 2021
** config_sprite2.C
** File description:
** config_sprite2
*/

#include "../includes/my.h"

void config_tower(tower_t *tower, int x, int y)
{
    tower->img = create_sprite("materials/flag.png");
    tower->img->pos = (sfVector2f) {x, y};
    tower->builded = 0;
    sfSprite_setPosition(tower->img->sprite, tower->img->pos);
}

void config_escape_ui(escape_t *escape)
{
    escape->bg = create_sprite("materials/escape.png");
    escape->b1 = create_sprite("materials/e_resume.png");
    escape->b1->pos = (sfVector2f) {780, 300};
    escape->b2 = create_sprite("materials/e_menu.png");
    escape->b2->pos = (sfVector2f) {780, 500};
    escape->b3 = create_sprite("materials/e_quit.png");
    escape->b3->pos = (sfVector2f) {780, 700};
    sfSprite_setPosition(escape->b1->sprite, escape->b1->pos);
    sfSprite_setPosition(escape->b2->sprite, escape->b2->pos);
    sfSprite_setPosition(escape->b3->sprite, escape->b3->pos);
}

void config_option_sprite2(game_t *game)
{
    game->opt->sound = create_sprite("materials/effect.png");
    game->opt->sound->pos = (sfVector2f) {820, 550};
    game->opt->music = create_sprite("materials/audio.png");
    game->opt->music->pos = (sfVector2f) {1300, 550};
    sfSprite_setPosition(game->opt->sound->sprite, game->opt->sound->pos);
    sfSprite_setPosition(game->opt->music->sprite, game->opt->music->pos);
    sfSprite_setPosition(game->opt->two->sprite, game->opt->two->pos);
    sfSprite_setPosition(game->opt->three->sprite, game->opt->three->pos);
    sfSprite_setPosition(game->opt->a->sprite, game->opt->a->pos);
    game->aa = 1;
    game->ma = 1;
}