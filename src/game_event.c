/*
** EPITECH PROJECT, 2021
** game_event.c
** File description:
** event in game
*/

#include "../includes/my.h"

void game_hovering_handling(game_t *game)
{
    game->mp = sfMouse_getPositionRenderWindow(game->window);
    if (is_contain(game, game->s) == sfTrue)
        change_texture("materials/settings_s.png", game->s);
    else if (is_contain(game, game->go) == sfTrue)
        change_go(game);
    else {
        for (int i = 0; i < 5; i++){
            flag_hover(game, &game->tower[i]);
        }
    }
}

void click_game(int a, game_t *game)
{
    reset_game_ui(game);
    switch (a)
    {
    case 1:
        game->escape = 1;
        break;
    case 2:
        go_action(game);
        change_go(game);
        break;
    }
}

void click_actions_game(game_t *game, sfEvent event)
{
    game->mp = sfMouse_getPositionRenderWindow(game->window);
    if (event.mouseButton.button == sfMouseLeft)
    {
        for (int i = 0; i < 5; i++)
            chose_build(game, &game->tower[i], i);
        if (is_contain(game, game->s) == sfTrue)
            click_game(1, game);
        if (is_contain(game, game->go) == sfTrue)
            click_game(2, game);
    }
}

void user_input_game2(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed){
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->escape = 1;
    }
}

void user_input_game(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtMouseButtonPressed)
        click_actions_game(game, event);
    else if (event.type == sfEvtMouseMoved){
        reset_game_ui(game);
        game_hovering_handling(game);
    }
    user_input_game2(game, event);
}