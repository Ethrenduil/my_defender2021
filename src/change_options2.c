/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender-quentin.vandersteene
** File description:
** change_options2
*/

#include "../includes/my.h"

void change_music(game_t *game)
{
    if (game->ma == 1)
        sfMusic_play(game->music);
    else
        sfMusic_stop(game->music);
}