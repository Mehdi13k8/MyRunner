/*
** EPITECH PROJECT, 2018
** hunter
** File description:
** error
*/

# include "my.h"

int	is_error(int ac, char **av, sf_list *graph)
{
  char  buff[4000];
  int   fd;

  if (ac != 2)
	  return (84);
  fd = open(av[1], O_RDONLY);
  if (fd == -1 && is_flag(ac,av) != 0)
	  return (84);
  read(fd, buff, 3999);
  buff[4000] = '\0';
  close (fd);
  getlengh(buff, graph);
}

void	getlengh(char *buff, sf_list *graph)
{
	int	i = 0;
	int	x = 0;
	int	y = 0;

	while (buff[i] != '\0') {
		if (buff[i] == '\n') {
			y +=1;
			x = 0;
		}
		x++;
		i++;
	}
	graph->yaxis = y;
	graph->xaxis = x;
}
