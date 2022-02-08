/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include "my.h"
#include <unistd.h>

static void my_putchar_error(char c)
{
    write(2, &c, 1);
}

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i++;
    }
    return (0);
}

void position_obs2(nb *go, char *map, int i)
{
    if (map[go->x] == '2' && go->obs2 == 0 &&
        go->obs1 != 0 && go->obs != 0) {
        go->obs2 = i == 0 ? 1 : i;
        go->num2 = 1;
    } else if (map[go->x] == '2' && go->obs3 == 0) {
        go->obs3 = i == 0 ? 1 : i;
        go->num3 = 1;
    }
}
