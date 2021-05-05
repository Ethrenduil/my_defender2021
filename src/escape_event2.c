/*
** EPITECH PROJECT, 2021
** escape_event2.c
** File description:
** event handling 2
*/

#include "../includes/my.h"

void escape_hovering_handling2(game_t *game, escape_t *escape)
{
    if (is_contain(game, escape->b3) == sfTrue)
        change_texture("materials/e_quit_s.png", escape->b3);
    else
        reset_escape_ui(escape);
}