/*
** EPITECH PROJECT, 2020
** score
** File description:
** score
*/

#include "my.h"

int find_size(int nb)
{
    int size = 0;

    if (nb != 0) {
        while (nb >= 1) {
            nb = nb / 10;
            size++;
        }
    } else
        size = 1;
    return (size);
}

int pow_10(int nb)
{
    int nbr = 1;
    int i = 1;

    while (i <= nb) {
        nbr = nbr * 10;
        i++;
    }
    return (nbr);
}

char *int_to_char(int nb)
{
    int size = find_size(nb);
    char *nbr = malloc(sizeof(char) * size);
    int i = 1;
    int nbr_1 = nb;
    int nbr_2 = 0;
    int nbr_3 = 0;

    while (i <= size) {
        nbr_3 = nbr_1 % pow_10(size - i);
        nbr_2 = (nbr_1 - nbr_3) / pow_10(size - i);
        nbr[i - 1] = nbr_2 + 48;
        nbr_1 = nbr_1 - nbr_2 * pow_10(size - i);
        i++;
    }
    nbr[size] = '\0';
    return (nbr);
}

void text_draw(nb *go, sf *cs)
{
    sfText *scre = sfText_create();
    sfVector2f postext;

    if (go->end == 0) {
        postext.x = 80;
        postext.y = 80;
    } else {
        postext.x = 780;
        postext.y = 700;
    }
    cs->font = sfFont_createFromFile("lib/my/stocky.ttf");
    sfText_setString(scre, int_to_char(go->score));
    sfText_setFont(scre, cs->font);
    sfText_setPosition(scre, postext);
    if (go->end == 0)
        sfText_setCharacterSize(scre, 50);
    else
        sfText_setCharacterSize(scre, 100);
    sfRenderWindow_drawText(cs->wdw, scre, NULL);
}
