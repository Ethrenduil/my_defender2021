/*
** EPITECH PROJECT, 2021
** game_event2.c
** File description:
** game_event2
*/

#include "../includes/my.h"

void build_click3(game_t *game, tower_t *tower)
{
    if (game->mp.x > 1700 && game->mp.x < 1781 &&
    game->mp.y > 646 && game->mp.y < 712)
        change_tower2(game, "materials/t1.png", tower, 1);
    if (game->mp.x > 1700 && game->mp.x < 1781 &&
    game->mp.y > 769 && game->mp.y < 834)
        change_tower2(game, "materials/t3.png", tower, 3);
    if (game->mp.x > 1846 && game->mp.x < 1928 &&
    game->mp.y > 646 && game->mp.y < 712)
        change_tower2(game, "materials/t2.png", tower, 2);
    if (game->mp.x > 1846 && game->mp.x < 1928 &&
    game->mp.y > 769 && game->mp.y < 834)
        change_tower2(game, "materials/t4.png", tower, 4);
}

void build_click2(game_t *game, tower_t *tower)
{
    if (game->mp.x > 1390 && game->mp.x < 1472 &&
    game->mp.y > 438 && game->mp.y < 505)
        change_tower2(game, "materials/t1.png", tower, 1);
    if (game->mp.x > 1390 && game->mp.x < 1472 &&
    game->mp.y > 557 && game->mp.y < 624)
        change_tower2(game, "materials/t3.png", tower, 3);
    if (game->mp.x > 1539 && game->mp.x < 1720 &&
    game->mp.y > 438 && game->mp.y < 505)
        change_tower2(game, "materials/t2.png", tower, 2);
    if (game->mp.x > 1539 && game->mp.x < 1720 &&
    game->mp.y > 557 && game->mp.y < 624)
        change_tower2(game, "materials/t4.png", tower, 4);
}

void build_click(game_t *game, tower_t *tower)
{
    if (game->mp.x > 1080 && game->mp.x < 1163 &&
    game->mp.y > 280 && game->mp.y < 343)
        change_tower2(game, "materials/t1.png", tower, 1);
    if (game->mp.x > 1080 && game->mp.x < 1163 &&
    game->mp.y > 396 && game->mp.y < 462)
        change_tower2(game, "materials/t3.png", tower, 3);
    if (game->mp.x > 1233 && game->mp.x < 1313 &&
    game->mp.y > 280 && game->mp.y < 343)
        change_tower2(game, "materials/t2.png", tower, 2);
    if (game->mp.x > 1233 && game->mp.x < 1313 &&
    game->mp.y > 396 && game->mp.y < 462)
        change_tower2(game, "materials/t4.png", tower, 4);
}

void flag_hover(game_t *game, tower_t *tower)
{
    if (tower->builded == 0) {
        if (is_contain(game, tower->img) == sfTrue)
            change_texture("materials/build.png", tower->img);
    }
}

void go_action(game_t *game)
{
    if (game->state == 0 && game->winit == 0){
        wave_init(game, game->e);
        game->state = 1;
    }
    else if (game->state == 0)
        game->state = 1;
    else
        game->state = 0;
}