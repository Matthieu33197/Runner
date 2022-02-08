/*
** EPITECH PROJECT, 2019
** mouvedrawdestroy
** File description:
** fonction mouv draw destroy
*/

#include <time.h>
#include "my.h"

void move_rect(int max_value, sf *cs, nb *go)
{
    cs->time = sfClock_getElapsedTime(cs->clock);
    go->seconds = cs->time.microseconds / 150000.0;
    if (go->seconds > 1.0) {
        cs->rect.left += 122;
        if (cs->rect.left >= max_value)
            cs->rect.left = 0;
        sfClock_restart(cs->clock);
    }
}

void draw_sprite(sf *cs, nb* go, sfS *spr)
{
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg7, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg6, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg5, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg4, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg4_b, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg3, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg3_b, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg2, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg2_b, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg1, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_bg1_b, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_spike1, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_spike2, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_spike3, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_spike4, NULL);
    if (go->yes == 0 && go->high == 1)
        sfRenderWindow_drawSprite(cs->wdw, spr->sprite_end, NULL);
    sfRenderWindow_drawSprite(cs->wdw, spr->sprite_player, NULL);
}

static void destroy2(sf *cs, sfT *text, sfS *spr, sfMusic *runner)
{
    sfSprite_destroy(spr->sprite_bg6);
    sfTexture_destroy(text->texture_bg6);
    sfSprite_destroy(spr->sprite_bg7);
    sfTexture_destroy(text->texture_bg7);
    sfTexture_destroy(text->texture_spike);
    sfSprite_destroy(spr->sprite_spike1);
    sfSprite_destroy(spr->sprite_spike2);
    sfSprite_destroy(spr->sprite_spike3);
    sfSprite_destroy(spr->sprite_spike4);
    sfTexture_destroy(text->texture_end);
    sfMusic_destroy(runner);
}

void destroy(sf *cs, sfT *text, sfS *spr, sfMusic *runner)
{
    sfRenderWindow_destroy(cs->wdw);
    sfTexture_destroy(text->texture_player);
    sfSprite_destroy(spr->sprite_player);
    sfTexture_destroy(text->texture_bg1);
    sfSprite_destroy(spr->sprite_bg1);
    sfSprite_destroy(spr->sprite_bg1_b);
    sfTexture_destroy(text->texture_bg2);
    sfSprite_destroy(spr->sprite_bg2);
    sfSprite_destroy(spr->sprite_bg2_b);
    sfSprite_destroy(spr->sprite_bg3);
    sfTexture_destroy(text->texture_bg3);
    sfSprite_destroy(spr->sprite_bg3_b);
    sfSprite_destroy(spr->sprite_bg4);
    sfTexture_destroy(text->texture_bg4);
    sfSprite_destroy(spr->sprite_bg4_b);
    sfSprite_destroy(spr->sprite_bg5);
    sfTexture_destroy(text->texture_bg5);
    destroy2(cs, text, spr, runner);
}
