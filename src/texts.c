/*
** EPITECH PROJECT, 2021
** texts.c
** File description:
** text handling
*/

#include "../includes/my.h"

text_t add_text(char *path, char *txt, sfVector2f pos, sfColor color)
{
    text_t a;

    a.text = sfText_create();
    a.font = sfFont_createFromFile(path);
    sfText_setPosition(a.text, pos);
    sfText_setString(a.text, txt);
    sfText_setFont(a.text, a.font);
    sfText_setCharacterSize(a.text, 20);
    sfText_setColor(a.text, color);
    return (a);
}

void change_nb(text_t text, int nb)
{
    char *txt = malloc(sizeof(int) * nb);
    txt = int_tochar(nb);
    sfText_setString(text.text, txt);
}

int remove_money2(game_t *game, int type)
{
    if (type == 3) {
        if (game->money - 200 >= 0) {
            game->money -= 200;
            change_nb(game->moneyt, game->money);
            return 0;
        }
        return 84;
    }
    if (type == 4) {
        if (game->money - 300 >= 0) {
            game->money -= 300;
            change_nb(game->moneyt, game->money);
            return 0;
        }
        return 84;
    }
}

int remove_money(game_t *game, int type)
{
    if (type == 1) {
        if (game->money - 100 >= 0) {
            game->money -= 100;
            change_nb(game->moneyt, game->money);
            return 0;
        }
        return 84;
    }
    if (type == 2) {
        if (game->money - 150 >= 0) {
            game->money -= 150;
            change_nb(game->moneyt, game->money);
            return 0;
        }
        return 84;
    }
    return remove_money2(game, type);
}