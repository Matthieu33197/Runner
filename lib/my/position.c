/*
** EPITECH PROJECT, 2020
** position
** File description:
** position func
*/

#include "my.h"

void position_obs(nb *go, char *map)
{
    int i = 0;
    while (map[go->x] != '2' && map[go->x] != 'E') {
        go->x++;
        i++;
    }
    if (map[go->x] == '2' && go->obs == 0) {
        go->obs = i == 0 ? 1 : i;
        go->num = 1;
    } else if (map[go->x] == '2' && go->obs1 == 0) {
        go->obs1 = i == 0 ? 1 : i;
        go->num1 = 1;
    } else
        position_obs2(go, map, i);
    if (go->obs == 0 || go->obs1 == 0 || go->obs2 == 0 || go->obs3 == 0)
        go->x++;
    i = 0;
}

void position_spike1(sf *cs, nb *go, int i) {
    if (go->num3 == 1) {
        i = go->obs3 + go->obs2 + go->obs1 + go->obs;
        cs->position_spike4.x = 1920 + (50 * i);
        go->num3 = 0;
    }
    if (go->num4 == 1) {
        cs->position_end.x = 1920 + (50 * go->end);
        go->num4 = 0;
    }
    if (go->score == 750) {
        go->high = 1;
        go->num4 = 1;
    }

}

void position_spike(sf *cs, nb *go)
{
    int i = 0;

    if (go->num == 1) {
        cs->position_spike1.x = 1920 + (50 * go->obs);
        go->num = 0;
    }
    if (go->num1 == 1) {
        cs->position_spike2.x = 1920 + (50 * (go->obs1 + go->obs));
        go->num1 = 0;
    }
    if (go->num2 == 1) {
        cs->position_spike3.x = 1920 + (50 * (go->obs2 + go->obs1 + go->obs));
        go->num2 = 0;
    }
    position_spike1(cs, go, i);
}

void set_position(sf *cs, nb *go, sfS *spr)
{
    position_obs(go, go->map);
    position_spike(cs, go);
    sfSprite_setPosition(spr->sprite_bg4, cs->position_bg4);
    sfSprite_setPosition(spr->sprite_bg4_b, cs->position_bg4_b);
    sfSprite_setPosition(spr->sprite_bg3, cs->position_bg3);
    sfSprite_setPosition(spr->sprite_bg3_b, cs->position_bg3_b);
    sfSprite_setPosition(spr->sprite_bg2, cs->position_bg2);
    sfSprite_setPosition(spr->sprite_bg2_b, cs->position_bg2_b);
    sfSprite_setPosition(spr->sprite_bg1, cs->position_bg1);
    sfSprite_setPosition(spr->sprite_bg1_b, cs->position_bg1_b);
    sfSprite_setPosition(spr->sprite_player, cs->position_player);
    sfSprite_setPosition(spr->sprite_spike1, cs->position_spike1);
    sfSprite_setPosition(spr->sprite_spike2, cs->position_spike2);
    sfSprite_setPosition(spr->sprite_spike3, cs->position_spike3);
    sfSprite_setPosition(spr->sprite_spike4, cs->position_spike4);
    sfSprite_setPosition(spr->sprite_end, cs->position_end);
}

void position(sf *cs, nb *go)
{
    position_obs(go, go->map);
    position_spike(cs, go);
    cs->position_bg1.x = 0;
    cs->position_bg1_b.x = 1920;
    cs->position_bg2.x = 0;
    cs->position_bg2_b.x = 1920;
    cs->position_bg3.x = 0;
    cs->position_bg3_b.x = 1920;
    cs->position_bg4.x = 0;
    cs->position_bg4_b.x = 1920;
    cs->position_player.x = 750;
    cs->position_player.y = 880;
    cs->position_spike1.y = 890;
    cs->position_spike2.y = 890;
    cs->position_spike3.y = 890;
    cs->position_spike4.y = 890;
    cs->position_end.y = 750;
}