/*
** EPITECH PROJECT, 2020
** lose_win
** File description:
** lose and win func
*/

#include "my.h"

static void draw_lose(sf *cs) {
    sfText *over = sfText_create();
    sfVector2f postext = {300, 400};
    sfFont *font2 = sfFont_createFromFile("lib/my/stocky.ttf");

    sfText_setString(over, "GAME OVER");
    sfText_setFont(over, font2);
    sfText_setPosition(over, postext);
    sfText_setCharacterSize(over, 150);
    sfRenderWindow_drawText(cs->wdw, over, NULL);
}

static void draw_win(sf *cs) {
    sfText *win = sfText_create();
    sfVector2f postext = {400, 400};
    sfFont *font3 = sfFont_createFromFile("lib/my/stocky.ttf");

    sfText_setString(win, "YOU WIN");
    sfText_setFont(win, font3);
    sfText_setPosition(win, postext);
    sfText_setCharacterSize(win, 150);
    sfRenderWindow_drawText(cs->wdw, win, NULL);
}

void lose_win(sf *cs, nb *go)
{
    if ((cs->position_spike1.x >= 750 && cs->position_spike1.x <= 800) ||
        (cs->position_spike2.x >= 750 && cs->position_spike2.x <= 800) ||
        (cs->position_spike3.x >= 750 && cs->position_spike3.x <= 800) ||
        (cs->position_spike4.x >= 750 && cs->position_spike4.x <= 800)) {
        if (go->jump == 0) {
            draw_lose(cs);
            go->end = 1;
        } else if (go->end == 0) {
            go->score++;
            go->score500++;
        }
    }
    if (cs->position_end.x <= 740 && cs->position_end.x >= 700 &&
        go->yes == 0) {
        draw_win(cs);
        go->end = 1;
    }
}

sfMusic *music(void)
{
    sfMusic *runner;

    runner = sfMusic_createFromFile("lib/my/music.ogg");
    sfMusic_setLoop(runner, sfTrue);
    sfMusic_play(runner);
    return (runner);
}
