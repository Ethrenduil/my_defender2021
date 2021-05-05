/*
** EPITECH PROJECT, 2021
** escape_event.c
** File description:
** escape_event
*/

#include "../includes/my.h"

void escape_hovering_handling(game_t *game, escape_t *escape)
{
    game->mp = sfMouse_getPositionRenderWindow(game->window);
    if (is_contain(game, escape->b1) == sfTrue)
        change_texture("materials/e_resume_s.png", escape->b1);
    else if (is_contain(game, escape->b2) == sfTrue)
        change_texture("materials/e_menu_s.png", escape->b2);
    else
        escape_hovering_handling2(game, escape);
}

void click_escape(int a, escape_t *escape, game_t *game)
{
    reset_escape_ui(escape);
    switch (a)
    {
    case 1:
        game->escape = 0;
        break;
    case 2:
        game->escape = 0;
        game->play = 0;
        kill_game(game);
        break;
    case 3:
        kill_game(game);
        sfRenderWindow_close(game->window);
        break;
    }
}

void click_actions_escape(game_t *game, escape_t *escape, sfEvent event)
{
    game->mp = sfMouse_getPositionRenderWindow(game->window);
    if (event.mouseButton.button == sfMouseLeft)
    {
        if (is_contain(game, escape->b1) == sfTrue)
            click_escape(1, escape, game);
        if (is_contain(game, escape->b2) == sfTrue)
            click_escape(2, escape, game);
        if (is_contain(game, escape->b3) == sfTrue)
            click_escape(3, escape, game);
    }
}

void user_input_escape2(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed){
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->escape = 0;
    }
}

void user_input_escape(game_t *game, escape_t *escape, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtMouseButtonPressed)
        click_actions_escape(game, escape, event);
    else if (event.type == sfEvtMouseMoved)
        escape_hovering_handling(game, escape);
    user_input_escape2(game, event);
}