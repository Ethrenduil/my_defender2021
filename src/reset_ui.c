/*
** EPITECH PROJECT, 2021
** reset_ui.c
** File description:
** reset the ui
*/

#include "../includes/my.h"

void reset_menu(menu_t *menu)
{
    change_texture("materials/play.png", menu->p);
    change_texture("materials/param.png", menu->pr);
    change_texture("materials/quit.png", menu->q);
}

void reset_escape_ui(escape_t *escape)
{
    change_texture("materials/e_resume.png", escape->b1);
    change_texture("materials/e_menu.png", escape->b2);
    change_texture("materials/e_quit.png", escape->b3);
}

void reset_game_ui(game_t *game)
{
    change_nb(game->wavet2, game->wave);
    change_nb(game->hpt, game->hp);
    change_nb(game->moneyt, game->money);
    change_texture("materials/settings.png", game->s);
    for (int i = 0 ; i < 5; i++)
        change_tower(game, "materials/flag.png", &game->tower[i]);
    if (game->state == 0)
        change_texture("materials/go.png", game->go);
    else
        change_texture("materials/pause.png", game->go);
}

void reset_options2(game_t *game)
{
    if (game->fps == 120){
        change_texture("materials/30.png", game->opt->one);
        change_texture("materials/60.png", game->opt->two);
        change_texture("materials/120_c.png", game->opt->three);
    }
    if (game->aa == 1)
        change_texture("materials/effect.png", game->opt->sound);
    else
        change_texture("materials/effect_no.png", game->opt->sound);
    if (game->ma == 1)
        change_texture("materials/audio.png", game->opt->music);
    else
        change_texture("materials/audio_no.png", game->opt->music);
}

void reset_options(game_t *game)
{
    game->opt->i->pos = (sfVector2f) {1400, 130};
    sfSprite_setPosition(game->opt->i->sprite, game->opt->i->pos);
    change_texture("materials/info.png", game->opt->i);
    change_texture("materials/apply.png", game->opt->a);
    if (game->screen == 1)
        change_texture("materials/cross_d.png", game->opt->c1);
    else
        change_texture("materials/cross.png", game->opt->c1);
    if (game->fps == 30){
        change_texture("materials/30_c.png", game->opt->one);
        change_texture("materials/60.png", game->opt->two);
        change_texture("materials/120.png", game->opt->three);
    }
    else if (game->fps == 60){
        change_texture("materials/30.png", game->opt->one);
        change_texture("materials/60_c.png", game->opt->two);
        change_texture("materials/120.png", game->opt->three);
    }
    reset_options2(game);
}