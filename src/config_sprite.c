/*
** EPITECH PROJECT, 2021
** config_sprite
** File description:
** Functions to config sprite
*/

#include "../includes/my.h"

void config_menu_sprite(game_t *game)
{
    game->option = 0;
    game->escape = 0;
    game->fps = 60;
    game->screen = 0;
    game->menu = malloc(sizeof(menu_t));
    game->menu->bg = create_sprite("materials/menu.png");
    game->window = create_window(game, "Dovahgolz Defender");
    game->menu->p = create_sprite("materials/play.png");
    game->menu->p->pos = (sfVector2f) {780, 500};
    game->menu->pr = create_sprite("materials/param.png");
    game->menu->pr->pos = (sfVector2f) {780, 700};
    game->menu->q = create_sprite("materials/quit.png");
    game->menu->q->pos = (sfVector2f) {780, 900};
    sfSprite_setPosition(game->menu->p->sprite, game->menu->p->pos);
    sfSprite_setPosition(game->menu->pr->sprite, game->menu->pr->pos);
    sfSprite_setPosition(game->menu->q->sprite, game->menu->q->pos);
}

void config_option_sprite(game_t *game)
{
    game->opt = malloc(sizeof(option_t));
    game->opt->bg = create_sprite("materials/options.png");
    game->opt->i = create_sprite("materials/info.png");
    game->opt->i->pos = (sfVector2f) {1400, 130};
    game->opt->c1 = create_sprite("materials/cross.png");
    game->opt->c1->pos = (sfVector2f) {1150, 328};
    game->opt->one = create_sprite("materials/30.png");
    game->opt->one->pos = (sfVector2f) {1000, 450};
    game->opt->two = create_sprite("materials/60_c.png");
    game->opt->two->pos = (sfVector2f) {1100, 450};
    game->opt->three = create_sprite("materials/120.png");
    game->opt->three->pos = (sfVector2f) {1200, 450};
    game->opt->a = create_sprite("materials/apply.png");
    game->opt->a->pos = (sfVector2f) {780, 780};
    sfSprite_setPosition(game->opt->i->sprite, game->opt->i->pos);
    sfSprite_setPosition(game->opt->c1->sprite, game->opt->c1->pos);
    sfSprite_setPosition(game->opt->one->sprite, game->opt->one->pos);
    config_option_sprite2(game);
}

void config_game_ui(game_t *game)
{
    game->bg = create_sprite("materials/game.png");
    game->s = create_sprite("materials/settings.png");
    game->s->pos = (sfVector2f) {1850, 0};
    game->base = create_sprite("materials/base.png");
    game->base->pos = (sfVector2f) {935, 790};
    game->pui = create_sprite("materials/p_info.png");
    game->hpt = add_text("materials/arial.TTF", "20",
    (sfVector2f) {120, 33}, (sfColor) {153, 0, 0, 255});
    game->moneyt = add_text("materials/arial.TTF", "300",
    (sfVector2f) {200, 33}, (sfColor) {218, 165, 32, 255});
    game->wavet = add_text("materials/arial.TTF", "wave",
    (sfVector2f) {390, 33}, (sfColor) {153, 102, 0, 255});
    game->wavet2 = add_text("materials/arial.TTF", "0",
    (sfVector2f) {440, 33}, (sfColor) {153, 102, 0, 255});
    sfSprite_setPosition(game->s->sprite, game->s->pos);
    sfSprite_setPosition(game->base->sprite, game->base->pos);
    config_game_ui2(game);
}

void config_game_ui2(game_t *game)
{
    game->go = create_sprite("materials/go.png");
    game->go->pos = (sfVector2f) {1785, 0};
    sfSprite_setPosition(game->go->sprite, game->go->pos);
    game->tower = malloc(sizeof(tower_t)*6);
    config_tower(&game->tower[0], 1080, 260);
    config_tower(&game->tower[1], 1390, 420);
    config_tower(&game->tower[2], 1700, 630);
    config_tower(&game->tower[3], 1420, 830);
    config_tower(&game->tower[4], 1180, 830);
}

void config_enemy_sprite(enemy_t *enemy, game_t *game, int speed)
{
    int a = 0;
    enemy->aspeed = speed;
    enemy->alive = 1;
    enemy->road = 0;
    enemy->frame = 0;
    enemy->img = create_sprite("materials/m1_run.png");
    enemy->img->pos = (sfVector2f) {1258, 0};
    sfSprite_setPosition(enemy->img->sprite, enemy->img->pos);
    sfSprite_setTextureRect	(enemy->img->sprite,
    (sfIntRect) {0, 0, 73, 76});
    enemy->aclock = sfClock_create();
    enemy->mclock = sfClock_create();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++, a++)
            enemy->frames[a] = (sfIntRect) {j * 73, i * 76, 73, 76};
    }
}