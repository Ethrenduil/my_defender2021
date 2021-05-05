/*
** EPITECH PROJECT, 2021
** event.c
** File description:
** event handling
*/

#include "../includes/my.h"

void menu_hovering_handling(game_t *game)
{
    game->mp = sfMouse_getPositionRenderWindow(game->window);
    if (game->mp.x > 780 && game->mp.x < 1160 &&
        game->mp.y > 500 && game->mp.y < 650)
        change_texture("materials/play_s.png", game->menu->p);
    else if (game->mp.x > 780 && game->mp.x < 1160 &&
        game->mp.y > 700 && game->mp.y < 850)
        change_texture("materials/param_s.png", game->menu->pr);
    else
        menu_hovering_handling2(game);
}

void click_menu(int a, game_t *game)
{
    reset_menu(game->menu);
    switch (a)
    {
    case 1:
        change_texture("materials/play_d.png", game->menu->p);
        init_game_var(game);
        game->play = 1;
        break;

    case 2:
        change_texture("materials/param_d.png", game->menu->pr);
        game->option = 1;
        break;

    case 3:
        change_texture("materials/quit_d.png", game->menu->q);
        sfRenderWindow_close(game->window);
        break;
    }
}

void click_actions_menu(game_t *game, sfEvent event)
{
    game->mp = sfMouse_getPositionRenderWindow(game->window);
    if (event.mouseButton.button == sfMouseLeft)
    {
        if (game->mp.x > 780 && game->mp.x < 1160 &&
        game->mp.y > 500 && game->mp.y < 650)
            click_menu(1, game);
        if (game->mp.x > 780 && game->mp.x < 1160 &&
        game->mp.y > 700 && game->mp.y < 850)
            click_menu(2, game);
        if (game->mp.x > 780 && game->mp.x < 1160 &&
        game->mp.y > 900 && game->mp.y < 1050)
            click_menu(3, game);
    }
}

void user_input_menu(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtMouseButtonPressed)
        click_actions_menu(game, event);
    if (event.type == sfEvtMouseMoved) {
        reset_menu(game->menu);
        menu_hovering_handling(game);
    }
}