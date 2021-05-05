/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** main.c
*/

#include "../includes/my.h"

void play(game_t *game)
{
    if (check_lost(game) == 1){
        game->escape = 0;
        game->play = 0;
        kill_game(game);
    }
    else if (game->state == 0){
        draw_game(game, game->e);
        enemy_handling(game, game->e);
        check_go(game);
    }
    else{
        enemy_handling(game, game->e);
        draw_game(game, game->e);
    }
}

void init_game_var(game_t *game)
{
    if (game->clock == NULL)
        game->clock = sfClock_create();
    else
        sfClock_restart(game->clock);
    game->cnb = 0;
    game->winit = 0;
    game->mnb = 0;
    game->hp = 20;
    game->wave = 0;
    game->money = 300;
    game->state = 0;
}

void main_menu(game_t *game, escape_t *escape)
{
    game->screen = 1;
    config_menu_sprite(game);
    config_option_sprite(game);
    config_game_ui(game);
    config_escape_ui(escape);
    while (sfRenderWindow_isOpen(game->window)) {
        if (game->play == 0)
            if (game->option == 1)
                draw_option(game);
            else
                draw_menu(game);
        else if (game->escape == 1){
            draw_escape(game, escape);
            check_go(game);
        }
        else
            play(game);
    }
}

int main(int nb, char **arg)
{
    game_t *game = malloc(sizeof(game_t));
    escape_t *escape = malloc(sizeof(escape_t));

    game->music = sfMusic_createFromFile("materials/background.ogg");
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_play(game->music);
    main_menu(game, escape);
    sfMusic_destroy(game->music);
    free_game(game);
    free_escape(escape);
    return (0);
}
