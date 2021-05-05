/*
** EPITECH PROJECT, 2021
** option_event.C
** File description:
** event in options
*/

#include "../includes/my.h"

void options_hovering_handling(game_t *game)
{
    game->mp = sfMouse_getPositionRenderWindow(game->window);
    if (game->mp.x > 1400 && game->mp.x < 1520 &&
        game->mp.y > 130 && game->mp.y < 280)
        draw_info(game);
    else if (is_contain(game, game->opt->c1) == sfTrue)
        change_texture("materials/cross_s.png", game->opt->c1);
    else
        options_hovering_handling2(game);
}

void click_options2(int a, game_t *game)
{
    switch (a)
    {
    case 3:
        change_quality(a, game);
        break;
    case 4:
        change_quality(a, game);
        break;
    case 5:
        game->option = 0;
        change_texture("materials/apply_d.png", game->opt->a);
        reset_window(game);
        break;
    }
}

void click_options(int a, game_t *game)
{
    reset_options(game);
    switch (a)
    {
    case 1:
        change_screen(game);
        break;
    case 2:
        change_quality(a, game);
        break;
    default:
        click_options2(a, game);
        break;
    }
}

void click_actions_options(game_t *game, sfEvent event)
{
    game->mp = sfMouse_getPositionRenderWindow(game->window);
    if (event.mouseButton.button == sfMouseLeft)
    {
        if (is_contain(game, game->opt->c1) == sfTrue)
            click_options(1, game);
        if (is_contain(game, game->opt->a) == sfTrue)
            click_options(5, game);
        click_actions_options2(game);
    }
}

void user_input_options(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtMouseButtonPressed) {
        click_actions_options(game, event);
        reset_options(game);
    }
    if (event.type == sfEvtMouseMoved) {
        reset_options(game);
        options_hovering_handling(game);
    }
}