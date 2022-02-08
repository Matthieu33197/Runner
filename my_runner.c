/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my runner
*/

#include <time.h>
#include "lib/my/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void event(sf *cs, nb *go)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
        cs->position_player.y = 700;
        go->jump = 1;
    } else {
        go->jump = 0;
        cs->position_player.y = 880;
    }
    if (cs->event.type == sfEvtClosed)
        sfRenderWindow_close(cs->wdw);
}

static void gameloop(sf *cs, nb *go, sfS *spr)
{
    set_position(cs, go, spr);
    sfSprite_setTextureRect(spr->sprite_player, cs->rect);
    sfRenderWindow_display(cs->wdw);
    draw_sprite(cs, go, spr);
    while (sfRenderWindow_pollEvent(cs->wdw, &cs->event))
        event(cs, go);
    if (go->end == 0) {
        move_rect(610, cs, go);
        background_speed(cs, go);
    }
    lose_win(cs, go);
    text_draw(go, cs);
}

static void set_number(nb *go, char **av)
{
    go->x = 0;
    go->high = 0;
    go->obs = 0;
    go->obs1 = 0;
    go->obs2 = 0;
    go->obs3 = 0;
    go->end = 0;
    go->num = 0;
    go->num1 = 0;
    go->num2 = 0;
    go->num3 = 0;
    go->score = 0;
    go->score500 = 0;
    go->speed = 1.80;
    if (av[1][0] == '-' && av[1][1] == 'i')
        go->yes = 1;
    else
        go->yes = 0;
}

static void gameset(char **av)
{
    sfVideoMode mode = {1656, 1080, 32};
    sf *cs = malloc(sizeof(sf));
    nb *go = malloc(sizeof(nb));
    sfT *text = malloc(sizeof(sfT));
    sfS *spr = malloc(sizeof(sfS));
    sfMusic *runner;

    set_number(go, av);
    cs->wdw = sfRenderWindow_create(mode, "SFML window", sfDefaultStyle, NULL);
    create(cs, go, text, spr);
    go->map = manage_map(cs, go, av);
    position(cs, go);
    runner = music();
    sfRenderWindow_setMouseCursorVisible(cs->wdw, sfFalse);
    while (sfRenderWindow_isOpen(cs->wdw))
        gameloop(cs, go, spr);
    destroy(cs, text, spr, runner);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
            description(av);
        else
            gameset(av);
    } else {
        my_putstr_error("./my_runner: bad arguments: ");
        my_putstr_error("0 given but 1 is required\n");
        return (84);
    }
}
