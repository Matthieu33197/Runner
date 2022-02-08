/*
** EPITECH PROJECT, 2020
** my func
** File description:
** my func
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

static int neg(int i)
{
    if (i == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        i = 147483648;
    }
    if (i < 0) {
        i = i * -1;
        my_putchar('-');
    }
    return (i);
}

void my_put_nbr(int nb)
{
    nb = neg(nb);
    if (nb < 10)
        my_putchar(nb + '0');
    else {
        my_put_nbr(nb/10);
        my_put_nbr(nb%10);
    }
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
