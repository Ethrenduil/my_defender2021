/*
** EPITECH PROJECT, 2021
** menu_event2.c
** File description:
** menu event handling 2
*/

#include "../includes/my.h"

void menu_hovering_handling2(game_t *game)
{
    if (game->mp.x > 780 && game->mp.x < 1160 &&
        game->mp.y > 900 && game->mp.y < 1050)
        change_texture("materials/quit_s.png", game->menu->q);
    else
        reset_menu(game->menu);
}