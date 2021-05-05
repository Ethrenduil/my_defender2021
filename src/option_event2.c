/*
** EPITECH PROJECT, 2021
** option_event2.c
** File description:
** option_event2
*/

#include "../includes/my.h"

void click_actions_options3(game_t *game)
{
    if (is_contain(game, game->opt->sound) == sfTrue){
        if (game->aa == 1)
            game->aa--;
        else
            game->aa++;
    }
    if (is_contain(game, game->opt->music) == sfTrue){
        if (game->ma == 1)
            game->ma--;
        else
            game->ma++;
        change_music(game);
    }
}

void click_actions_options2(game_t *game)
{
    if (is_contain(game, game->opt->one) == sfTrue)
        click_options(2, game);
    if (is_contain(game, game->opt->two) == sfTrue)
        click_options(3, game);
    if (is_contain(game, game->opt->three) == sfTrue)
        click_options(4, game);
    click_actions_options3(game);
}

void options_hovering_handling4(game_t *game)
{
    if (is_contain(game, game->opt->sound) == sfTrue)
        change_texture("materials/effect_h.png", game->opt->sound);
    else if (is_contain(game, game->opt->music) == sfTrue)
        change_texture("materials/audio_h.png", game->opt->music);
}

void options_hovering_handling3(game_t *game)
{
    if (is_contain(game, game->opt->two) == sfTrue)
        change_texture("materials/60_h.png", game->opt->two);
    else if (is_contain(game, game->opt->three) == sfTrue)
        change_texture("materials/120_h.png", game->opt->three);
    else
        options_hovering_handling4(game);
}

void options_hovering_handling2(game_t *game)
{
    if (is_contain(game, game->opt->a) == sfTrue)
        change_texture("materials/apply_s.png", game->opt->a);
    else if (is_contain(game, game->opt->one) == sfTrue)
        change_texture("materials/30_h.png", game->opt->one);
    else
        options_hovering_handling3(game);
}
