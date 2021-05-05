/*
** EPITECH PROJECT, 2021
** window_texts.c
** File description:
** window_texts.c
*/

#include "../includes/my.h"

image_t *create_sprite(char *img)
{
    image_t *image = malloc(sizeof(image_t));
    image->texture = sfTexture_createFromFile(img, NULL);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    return image;
}

sfBool is_contain(game_t *game, image_t *img)
{
    sfFloatRect bound = sfSprite_getGlobalBounds(img->sprite);
    return sfFloatRect_contains(&bound, game->mp.x, game->mp.y);
}

void change_texture(char *img, image_t *image)
{
    sfTexture_destroy(image->texture);
    image->texture = sfTexture_createFromFile(img, NULL);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
}

void change_tower(game_t *game, char *img, tower_t *tower)
{
    if (tower->builded == 0) {
        sfTexture_destroy(tower->img->texture);
        tower->img->texture = sfTexture_createFromFile(img, NULL);
        sfSprite_setTexture(tower->img->sprite, tower->img->texture, sfTrue);
    }
    if (game->play == 0) {
        tower->builded = 0;
        sfTexture_destroy(tower->img->texture);
        tower->img->texture = sfTexture_createFromFile(img, NULL);
        sfSprite_setTexture(tower->img->sprite, tower->img->texture, sfTrue);
    }
}

void change_tower2(game_t *game, char *img, tower_t *tower, int type)
{
    if (remove_money(game, type) == 84)
        return;
    tower->builded = 1;
    tower->type = type;
    sfTexture_destroy(tower->img->texture);
    tower->img->texture = sfTexture_createFromFile(img, NULL);
    sfSprite_setTexture(tower->img->sprite, tower->img->texture, sfTrue);
}
