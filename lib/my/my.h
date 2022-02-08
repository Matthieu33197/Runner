/*
** EPITECH PROJECT, 2019
** my
** File description:
** all my
*/

#ifndef __MY_H__
#define __MY_H__

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stddef.h>
#include <stdlib.h>
#include <SFML/System/Clock.h>

typedef struct sfT_struct
{
    sfTexture *texture_bg1;
    sfTexture *texture_bg1_b;
    sfTexture *texture_bg2;
    sfTexture *texture_bg2_b;
    sfTexture *texture_bg3;
    sfTexture *texture_bg3_b;
    sfTexture *texture_bg4;
    sfTexture *texture_bg4_b;
    sfTexture *texture_bg5;
    sfTexture *texture_bg6;
    sfTexture *texture_bg7;
    sfTexture *texture_player;
    sfTexture *texture_spike;
    sfTexture *texture_end;
} sfT;

typedef struct sfS_struct
{
    sfSprite *sprite_bg1;
    sfSprite *sprite_bg1_b;
    sfSprite *sprite_bg2;
    sfSprite *sprite_bg2_b;
    sfSprite *sprite_bg3;
    sfSprite *sprite_bg3_b;
    sfSprite *sprite_bg4;
    sfSprite *sprite_bg4_b;
    sfSprite *sprite_bg5;
    sfSprite *sprite_bg6;
    sfSprite *sprite_bg7;
    sfSprite *sprite_player;
    sfSprite *sprite_spike1;
    sfSprite *sprite_spike2;
    sfSprite *sprite_spike3;
    sfSprite *sprite_spike4;
    sfSprite *sprite_end;
} sfS;

typedef struct sf_struct
{
    sfClock *clock;
    sfTime time;
    sfRenderWindow *wdw;
    sfEvent event;
    sfVector2f position_end;
    sfVector2f position_spike1;
    sfVector2f position_spike2;
    sfVector2f position_spike3;
    sfVector2f position_spike4;
    sfVector2f position_player;
    sfVector2f position_bg4;
    sfVector2f position_bg4_b;
    sfVector2f position_bg3;
    sfVector2f position_bg3_b;
    sfVector2f position_bg2;
    sfVector2f position_bg2_b;
    sfVector2f position_bg1;
    sfVector2f position_bg1_b;
    sfIntRect rect;
    sfFont *font;
} sf;

typedef struct nb_struct
{
    int score;
    int score500;
    int spike;
    int obs;
    int obs1;
    int obs2;
    int obs3;
    int end;
    int x;
    int num;
    int num1;
    int num2;
    int num3;
    int num4;
    int jump;
    int yes;
    int high;
    float speed;
    float seconds;
    char *map;
} nb;

char *manage_map(sf *cs, nb *go, char **av);
void description(char **av);
int my_strlen(char *str);
void move_rect(int max_value, sf *cs, nb *go);
void draw_sprite(sf *cs, nb* go, sfS *spr);
void destroy(sf *cs, sfT *text, sfS *spr, sfMusic *runner);
void my_putchar(char c);
void my_put_nbr(int nb);
int my_putstr(char const *str);
void lose_win(sf *cs, nb *go);
void create_texture(sfT *text);
void create_sprite(sfS *spr);
void set_texture(sfS *spr, sfT *text);
void create(sf *cs, nb *go, sfT *text, sfS *spr);
void position_obs(nb *go, char *map);
void position_spike(sf *cs, nb *go);
void set_position(sf *cs, nb *go, sfS *spr);
void position(sf *cs, nb *go);
int find_size(int nb);
int pow_10(int nb);
char *int_to_char(int nb);
void text_draw(nb *go, sf *cs);
void background_speed(sf *cs, nb *go);
sfMusic *music(void);
int my_putstr_error(char const *str);
void position_obs2(nb *go, char *map, int i);

#endif
