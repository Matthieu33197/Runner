/*
** EPITECH PROJECT, 2020
** texture and sprite
** File description:
** texture and sprite
*/

#include "my.h"

void create(sf *cs, nb *go, sfT *text, sfS *spr)
{
    create_texture(text);
    create_sprite(spr);
    set_texture(spr, text);
    cs->rect.top = 0;
    cs->rect.left = 0;
    cs->rect.width = 122;
    cs->rect.height = 118;
    cs->clock = sfClock_create();
}

void create_texture(sfT *text)
{
    text->texture_bg1 = sfTexture_createFromFile("lib/my/pic/1.png", NULL);
    text->texture_bg2 = sfTexture_createFromFile("lib/my/pic/2.png", NULL);
    text->texture_bg3 = sfTexture_createFromFile("lib/my/pic/3.png", NULL);
    text->texture_bg4 = sfTexture_createFromFile("lib/my/pic/4.png", NULL);
    text->texture_bg5 = sfTexture_createFromFile("lib/my/pic/5.png", NULL);
    text->texture_bg6 = sfTexture_createFromFile("lib/my/pic/6.png", NULL);
    text->texture_bg7 = sfTexture_createFromFile("lib/my/pic/7.png", NULL);
    text->texture_player = sfTexture_createFromFile("lib/my/pic/player.png",
                                                    NULL);
    text->texture_spike = sfTexture_createFromFile("lib/my/pic/spike.png",
                                                   NULL);
    text->texture_end = sfTexture_createFromFile("lib/my/pic/end.png", NULL);
}

void create_sprite(sfS *spr)
{
    spr->sprite_player = sfSprite_create();
    spr->sprite_bg1 = sfSprite_create();
    spr->sprite_bg1_b = sfSprite_create();
    spr->sprite_bg2 = sfSprite_create();
    spr->sprite_bg2_b = sfSprite_create();
    spr->sprite_bg3 = sfSprite_create();
    spr->sprite_bg3_b = sfSprite_create();
    spr->sprite_bg4 = sfSprite_create();
    spr->sprite_bg4_b = sfSprite_create();
    spr->sprite_bg5 = sfSprite_create();
    spr->sprite_bg6 =  sfSprite_create();
    spr->sprite_bg7 = sfSprite_create();
    spr->sprite_spike1 = sfSprite_create();
    spr->sprite_spike2 = sfSprite_create();
    spr->sprite_spike3 = sfSprite_create();
    spr->sprite_spike4 = sfSprite_create();
    spr->sprite_end = sfSprite_create();
}

void set_texture(sfS *spr, sfT *text)
{
    sfSprite_setTexture(spr->sprite_player, text->texture_player, sfTrue);
    sfSprite_setTexture(spr->sprite_bg1, text->texture_bg1, sfTrue);
    sfSprite_setTexture(spr->sprite_bg1_b, text->texture_bg1, sfTrue);
    sfSprite_setTexture(spr->sprite_bg2, text->texture_bg2, sfTrue);
    sfSprite_setTexture(spr->sprite_bg2_b, text->texture_bg2, sfTrue);
    sfSprite_setTexture(spr->sprite_bg3, text->texture_bg3, sfTrue);
    sfSprite_setTexture(spr->sprite_bg3_b, text->texture_bg3, sfTrue);
    sfSprite_setTexture(spr->sprite_bg4, text->texture_bg4, sfTrue);
    sfSprite_setTexture(spr->sprite_bg4_b, text->texture_bg4, sfTrue);
    sfSprite_setTexture(spr->sprite_bg5, text->texture_bg5, sfTrue);
    sfSprite_setTexture(spr->sprite_bg6, text->texture_bg6, sfTrue);
    sfSprite_setTexture(spr->sprite_bg7, text->texture_bg7, sfTrue);
    sfSprite_setTexture(spr->sprite_spike1, text->texture_spike, sfTrue);
    sfSprite_setTexture(spr->sprite_spike2, text->texture_spike, sfTrue);
    sfSprite_setTexture(spr->sprite_spike3, text->texture_spike, sfTrue);
    sfSprite_setTexture(spr->sprite_spike4, text->texture_spike, sfTrue);
    sfSprite_setTexture(spr->sprite_end, text->texture_end, sfTrue);
}