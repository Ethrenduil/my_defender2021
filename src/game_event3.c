/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender-quentin.vandersteene
** File description:
** game_event3
*/

#include "../includes/my.h"

void build_click4(game_t *game, tower_t *tower)
{
    if (game->mp.x > 1420 && game->mp.x < 1500 &&
    game->mp.y > 847 && game->mp.y < 912)
        change_tower2(game, "materials/t1.png", tower, 1);
    if (game->mp.x > 1420 && game->mp.x < 1500 &&
    game->mp.y > 968 && game->mp.y < 1033)
        change_tower2(game, "materials/t3.png", tower, 3);
    if (game->mp.x > 1567 && game->mp.x < 1648 &&
    game->mp.y > 847 && game->mp.y < 912)
        change_tower2(game, "materials/t2.png", tower, 2);
    if (game->mp.x > 1567 && game->mp.x < 1648 &&
    game->mp.y > 968 && game->mp.y < 1033)
        change_tower2(game, "materials/t4.png", tower, 4);
}
    //config_tower(&game->tower[3], 1420, 830);
    //config_tower(&game->tower[4], 1180, 830);

void build_click5(game_t *game, tower_t *tower)
{
    if (game->mp.x > 1180 && game->mp.x < 1262 &&
    game->mp.y > 847 && game->mp.y < 912)
        change_tower2(game, "materials/t1.png", tower, 1);
    if (game->mp.x > 1180 && game->mp.x < 1262 &&
    game->mp.y > 968 && game->mp.y < 1033)
        change_tower2(game, "materials/t3.png", tower, 3);
    if (game->mp.x > 1329 && game->mp.x < 1410 &&
    game->mp.y > 847 && game->mp.y < 912)
        change_tower2(game, "materials/t2.png", tower, 2);
    if (game->mp.x > 1329 && game->mp.x < 1410 &&
    game->mp.y > 968 && game->mp.y < 1033)
        change_tower2(game, "materials/t4.png", tower, 4);
}

void chose_build(game_t *game, tower_t *tower, int i)
{
    if (tower->builded == 1)
        return;
    switch (i)
    {
    case 0:
        build_click(game, &game->tower[0]);
        break;
    case 1:
        build_click2(game, &game->tower[1]);
        break;
    case 2:
        build_click3(game, &game->tower[2]);
        break;
    case 3:
        build_click4(game, &game->tower[3]);
        break;
    case 4:
        build_click5(game, &game->tower[4]);
        break;
    }
}