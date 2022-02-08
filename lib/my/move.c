/*
** EPITECH PROJECT, 2020
** move
** File description:
** all move
*/

#include "my.h"

static void move_back(sf *cs, nb *go)
{
    cs->position_bg1.x -= go->speed;
    cs->position_bg2.x -= 0.50;
    cs->position_bg3.x -= 0.35;
    cs->position_bg4.x -= 0.25;
    cs->position_bg1_b.x -= go->speed;
    cs->position_bg2_b.x -= 0.50;
    cs->position_bg3_b.x -= 0.35;
    cs->position_bg4_b.x -= 0.25;
    if (go->obs != 0)
        cs->position_spike1.x -= go->speed;
    if (go->obs1 != 0)
        cs->position_spike2.x -= go->speed;
    if (go->obs2 != 0)
        cs->position_spike3.x -= go->speed;
    if (go->obs3 != 0)
        cs->position_spike4.x -= go->speed;
    cs->position_end.x -= go->speed;
}

static void background_speed2(sf *cs, nb *go)
{
    if (cs->position_spike1.x <= -20) {
        go->obs = 0;
        cs->position_spike1.x = -10;
    }
    if (cs->position_spike2.x <= -20) {
        go->obs1 = 0;
        cs->position_spike2.x = -10;
    }
    if (cs->position_spike3.x <= -20) {
        go->obs2 = 0;
        cs->position_spike3.x = -10;
    }
    if (cs->position_spike4.x <= -20) {
        go->obs3 = 0;
        cs->position_spike4.x = -10;
    }
    if (go->score500 == 250) {
        go->speed *= 1.5;
        go->score500 = 0;
    }
}

void background_speed(sf *cs, nb *go)
{
    move_back(cs, go);
    if (cs->position_bg1.x <= -1920)
        cs->position_bg1.x = 1920;
    if (cs->position_bg1_b.x <= -1920)
        cs->position_bg1_b.x = 1920;
    if (cs->position_bg2.x <= -1920)
        cs->position_bg2.x = 1920;
    if (cs->position_bg2_b.x <= -1920)
        cs->position_bg2_b.x = 1920;
    if (cs->position_bg3.x <= -1920)
        cs->position_bg3.x = 1920;
    if (cs->position_bg3_b.x <= -1920)
        cs->position_bg3_b.x = 1920;
    if (cs->position_bg4.x <= -1920)
        cs->position_bg4.x = 1920;
    if (cs->position_bg4_b.x <= -1920)
        cs->position_bg4_b.x = 1920;
    background_speed2(cs, go);
}
