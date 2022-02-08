/*
** EPITECH PROJECT, 2019
** desc_map
** File description:
** open desc and manage map
*/

#include <time.h>
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void error(int fs)
{
    if (fs == -1)
        my_putstr("Bad name of map file\n");
}

char *manage_map(sf *cs, nb *go, char **av)
{
    char courant;
    int i = 0;
    int fs = open("map", O_RDONLY);
    error(fs);
    int fd = read(fs, &courant, 1);
    char *map = malloc(sizeof(char) * 1000);
    int nb_2;

    nb_2 = 0;
    while (courant != 'E') {
        map[i] = courant;
        i++;
        fd = read(fs, &courant, 1);
    }
    map[i] = 'E';
    close(fs);
    return (map);
}

void description(char **av)
{
    char courant;
    int i = 0;
    int fs = open("desc", O_RDONLY);
    int fd = read(fs, &courant, 1);
    char *desc = malloc(sizeof(char));

    while (courant != '*') {
            desc[i] = courant;
            i++;
            fd = read(fs, &courant, 1);
        }
    write(1, desc, (my_strlen(desc) - 1));
    close(fs);
}