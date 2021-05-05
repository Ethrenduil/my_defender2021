/*
** EPITECH PROJECT, 2021
** change_options.c
** File description:
** change settings functions
*/

#include "../includes/my.h"

void kill_game(game_t *game)
{
    if (game->winit == 1 && game->cnb > 0) {
        free(game->e);
    }
    for (int i = 0; i < 5; i++)
        change_tower(game, "materials/flag.png", &game->tower[i]);
    init_game_var(game);
    reset_game_ui(game);
}

void reset_window(game_t *game)
{
    sfRenderWindow_close(game->window);
    game->window = create_window(game, "Dovahgolz Defender");
}

void change_screen(game_t *game)
{
    if (game->screen == 1) {
        game->screen = 0;
        change_texture("materials/cross.png", game->opt->c1);
    }
    else {
        game->screen = 1;
        change_texture("materials/cross_d.png", game->opt->c1);
    }

}

void change_quality(int a, game_t *game)
{
    switch (a)
    {
    case 2:
        game->fps = 30;
        break;
    case 3:
        game->fps = 60;
        break;
    case 4:
        game->fps = 120;
        break;
    }
}

void change_go(game_t *game)
{
    if (game->state == 0)
        change_texture("materials/go_s.png", game->go);
    else
        change_texture("materials/pause_s.png", game->go);
}