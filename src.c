/*
** EPITECH PROJECT, 2018
** graph
** File description:
** mehd
*/

# include "my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		my_putchar(str[i]);
		i++;
	}
}
