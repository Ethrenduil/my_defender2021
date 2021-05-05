/*
** EPITECH PROJECT, 2021
** enemy.c
** File description:
** enemy's functions
*/

#include "../includes/my.h"

void move_enemy2(game_t *game, enemy_t *enemy)
{
    if (enemy->road == 2) {
        enemy->img->pos.y += 2;
        if (enemy->img->pos.y >= 814)
            enemy->road++;
    }
    else if (enemy->road == 3) {
        enemy->img->pos.x -= 3;
        if (enemy->img->pos.x <= 960){
            enemy->alive = 0;
            change_nb(game->hpt, --game->hp);
        }
    }
}

void move_enemy(game_t *game, enemy_t *enemy)
{
    if (enemy->road == 0) {
        enemy->img->pos.y += 2;
        if (enemy->img->pos.y >= 394)
            enemy->road++;
    }
    else if (enemy->road == 1) {
        enemy->img->pos.x += 3;
        if (enemy->img->pos.x >= 1680)
            enemy->road++;
    }
    else
        move_enemy2(game, enemy);
    sfSprite_setPosition(enemy->img->sprite, enemy->img->pos);
}

void draw_enemy(game_t *game, enemy_t *enemy, int nb)
{
    sfTime time = sfClock_getElapsedTime(enemy->mclock);
    enemy_animation(game, enemy);
    if (sfTime_asMilliseconds(time) > nb){
        move_enemy(game, enemy);
        sfClock_restart(enemy->mclock);
    }
    sfRenderWindow_drawSprite(game->window, enemy->img->sprite, NULL);
}

void change_enemy_frame(enemy_t *enemy, sfIntRect frame)
{
    sfSprite_setTextureRect(enemy->img->sprite, frame);
}

void enemy_animation(game_t *game, enemy_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->aclock);
    if (sfTime_asMilliseconds(time) > enemy->aspeed){
        enemy->frame++;
        if (enemy->frame == 25)
            enemy->frame = 0;
        change_enemy_frame(enemy, enemy->frames[enemy->frame]);
        sfClock_restart(enemy->aclock);
    }
}
