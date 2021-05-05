/*
** EPITECH PROJECT, 2021
** window.c
** File description:
** Functions about windows all made by jules
*/

#include "../includes/my.h"

sfRenderWindow *create_window(game_t *game, char *title)
{
    sfVideoMode mode = {1920, 1080, 32};
    if (game->screen == 1) {
        sfRenderWindow *window = sfRenderWindow_create(mode, title,
            sfFullscreen, NULL);
        sfRenderWindow_setFramerateLimit(window, game->fps);
        return window;
    }
    else {
        sfRenderWindow *window = sfRenderWindow_create(mode, title,
            sfClose, NULL);
        sfRenderWindow_setFramerateLimit(window, game->fps);
        return window;
    }
}