/*
** EPITECH PROJECT, 2021
** enemy2.c
** File description:
** second enemy's functions
*/

#include "../includes/my.h"

void draw_all_enemy(game_t *game, enemy_t *enemy)
{
    int a = 0;
    for (int i = 0; i < game->cnb; i++) {
        if (enemy[i].alive == 1) {
            draw_enemy(game, &enemy[i], 30);
            a++;
        }
    }
    if (a == 0 && game->cnb == game->mnb) {
        game->winit = 0;
        game->state = 0;
    }
}

void wave_init(game_t *game, enemy_t *enemy)
{
    if (game->winit == 0){
        game->mnb += (rand() % (20 - 10 + 1)) + 10;
        if (game->e != NULL)
            free(game->e);
        game->e = malloc(sizeof(enemy_t)* game->mnb);
        game->winit = 1;
        game->wave++;
        change_nb(game->wavet2, game->wave);
        game->state = 1;
    }
}

void enemy_handling(game_t *game, enemy_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    srand(sfTime_asMicroseconds(time));
    int spawn = (rand() % (10 - 1 + 1)) + 1;

    if (game->cnb < game->mnb){
        if (sfTime_asSeconds(time) > spawn){
            config_enemy_sprite(&game->e[game->cnb], game, 50);
            game->cnb++;
            sfClock_restart(game->clock);
        }
    }
}