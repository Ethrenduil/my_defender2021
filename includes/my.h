/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Create a defender game
*/

#ifndef h_defender
#define h_defender

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
} text_t;

typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int hovered;
} image_t;

typedef struct menu_s {
    image_t *bg;
    image_t *p;
    image_t *pr;
    image_t *q;
} menu_t;

typedef struct escape_s {
    image_t *bg;
    image_t *b1;
    image_t *b2;
    image_t *b3;
} escape_t;

typedef struct enemy_s {
    image_t *img;
    sfClock *aclock;
    sfClock *mclock;
    sfIntRect frames[25];
    int frame;
    int road;
    int aspeed;
    int alive;
} enemy_t;

typedef struct option_s {
    image_t *bg;
    image_t *i;
    image_t *c1;
    image_t *one;
    image_t *two;
    image_t *three;
    image_t *sound;
    image_t *music;
    image_t *a;
} option_t;

typedef struct tower_s {
    image_t *img;
    int builded;
    int type;
} tower_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfMusic *music;
    sfMusic *button;
    sfEvent event;
    sfVector2i mp;
    image_t *bg;
    image_t *s;
    image_t *pui;
    image_t *base;
    image_t *go;
    tower_t *tower;
    menu_t *menu;
    option_t *opt;
    sfClock *clock;
    enemy_t *e;
    text_t hpt;
    text_t wavet;
    text_t wavet2;
    text_t moneyt;
    int fps;
    int screen;
    int play;
    int option;
    int hp;
    int money;
    int wave;
    int mnb;
    int cnb;
    int winit;
    int state;
    int escape;
    int aa;
    int ma;
} game_t;

// Lib functions

void my_putchar(char c);
int show_number(int nb);
int show_string(char const *str);
char *reverse_string(char *str);
int to_number(char const *str);
int is_prime_number(int nb);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
int my_strlen(char const *str);
void show_params(int nb, char **arg);
int is_alphanum(char c);
void my_puterror(char c);
int show_error(char const *str);
int nb_arg(int nb);
int is_number(char c);
int is_signe(char c);
int my_to_number(char *str);
char *int_tochar(int nb);

// main.c

void init_game_var(game_t *game);
void play(game_t *game);
void main_menu(game_t *game, escape_t *escape);

// free.c

void free_game(game_t *game);
void free_escape(escape_t *escape);

// window_img.C

image_t *create_sprite(char *img);
void change_texture(char *img, image_t *image);
void change_tower(game_t *game, char *img, tower_t *tower);
void change_tower2(game_t *game, char *img, tower_t *tower, int type);
sfBool is_contain(game_t *game, image_t *img);

// reset_ui.c
void reset_menu(menu_t *menu);
void reset_options(game_t *game);
void reset_game_ui(game_t *game);
void reset_escape_ui(escape_t *escape);

// window.c

sfRenderWindow *create_window(game_t *game, char *title);

// menu_event.c

void menu_hovering_handling(game_t *game);
void click_menu(int a, game_t *game);
void click_actions_menu(game_t *game, sfEvent event);
void user_input_menu(game_t *game, sfEvent event);

// menu_event2.c

void menu_hovering_handling2(game_t *game);

// option_event.c

void options_hovering_handling(game_t *game);
void click_options(int a, game_t *game);
void click_options2(int a, game_t *game);
void click_actions_options(game_t *game, sfEvent event);
void user_input_options(game_t *game, sfEvent event);

// option_event2.c

void click_actions_options2(game_t *game);
void options_hovering_handling2(game_t *game);
void cross_hovered(int a, game_t *game);

// escape_event.c

void escape_hovering_handling(game_t *game, escape_t *escape);
void click_escape(int a, escape_t *escape, game_t *game);
void click_actions_escape(game_t *game, escape_t *escape, sfEvent event);
void user_input_escape(game_t *game, escape_t *escape, sfEvent event);

// escape_event2.c
void user_input_escape2(game_t *game, sfEvent event);
void escape_hovering_handling2(game_t *game, escape_t *escape);

// game_event.c

void game_hovering_handling(game_t *game);
void click_game(int a, game_t *game);
void click_actions_game(game_t *game, sfEvent event);
void user_input_game(game_t *game, sfEvent event);

// game_event2.c

void go_action(game_t *game);
void game_hovering_handling2(game_t *game);
void flag_hover(game_t *game, tower_t *tower);
void build_click(game_t *game, tower_t *tower);
void build_click2(game_t *game, tower_t *tower);
void build_click3(game_t *game, tower_t *tower);
void build_click4(game_t *game, tower_t *tower);
void build_click5(game_t *game, tower_t *tower);

// draw.c

void draw_menu(game_t *game);
void draw_option(game_t *game);
void draw_game(game_t *game, enemy_t *enemy);
void draw_game2(game_t *game);
void draw_info(game_t *game);

// draw2.c

void draw_escape(game_t *game, escape_t *escape);
void draw_tower(game_t *game, tower_t *tower);

// config_sprite.c

void config_menu_sprite(game_t *game);
void config_option_sprite(game_t *game);
void config_game_ui(game_t *game);
void config_game_ui2(game_t *game);
void config_enemy_sprite(enemy_t *enemy, game_t *game, int a);

// config_sprite2.c

void config_tower(tower_t *tower, int x, int y);
void config_escape_ui(escape_t *escape);
void config_option_sprite2(game_t *game);

// change_options.c

void change_quality(int a, game_t *game);
void change_screen(game_t *game);
void reset_window(game_t *game);
void change_go(game_t *game);
void kill_game(game_t *game);

// change_options2.c

void change_music(game_t *game);

// enemy.c

void draw_enemy(game_t *game, enemy_t *enemy, int nb);
void enemy_animation(game_t *game, enemy_t *enemy);
void change_enemy_frame(enemy_t *enemy, sfIntRect frame);
void move_enemy(game_t *game, enemy_t *enemy);
void move_enemy2(game_t *game, enemy_t *enemy);

// enemy2.c

void draw_all_enemy(game_t *game, enemy_t *enemy);
void wave_init(game_t *game, enemy_t *enemy);
void enemy_handling(game_t *game, enemy_t *enemy);

// checks.c

int check_lost(game_t *game);
void check_go(game_t *game);

// text.c

text_t add_text(char *path, char *txt, sfVector2f pos, sfColor color);
void change_nb(text_t text, int nb);
int remove_money(game_t *game, int type);
void chose_build(game_t *game, tower_t *tower, int i);

#endif /* !h_defender */
