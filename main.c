/*
** EPITECH PROJECT, 2017
** runner
** File description:
** main
*/

# include "my.h"

void	to_hell(sf_list	*graph)
{
	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue && graph->scale.y < 600) {
		graph->scale.y +=3;
		graph->sanic_rect.left = 7;
		graph->sanic_rect.width = 45;
		graph->sanic_rect.top = 75+50;
		graph->sanic_rect.height = -70;
		graph->move = 1;
	}
	else if (graph->move == 0)
		reset_rect(graph);
	graph->spacekey = 1;
}

void	rect_cut(sf_list *graph)
{
	graph->rect.left = 0;
	graph->rect.width = 1212,5;
	graph->rect.top = 0;
	graph->rect.height = 632;
	graph->sanic_rect.left = 0;
	graph->sanic_rect.width = 55;
	graph->sanic_rect.top = 20;
	graph->sanic_rect.height = 30;
	graph->Robotnic_rect1.left = 265;
	graph->Robotnic_rect1.width = -45;
	graph->Robotnic_rect1.top = 55;
	graph->Robotnic_rect1.height = 60;
	graph->Robotnic_rect2.left = 0;
	graph->Robotnic_rect2.width = 55;
	graph->Robotnic_rect2.top = 20;
	graph->Robotnic_rect2.height = 30;
}

void	vec_declaration(sf_list *graph)
{
	graph->setscale.x = 1;
	graph->setscale.y = 0.2;
	graph->platform.x = 0;
	graph->platform.y = 0;
}

void	clock_move(sf_list *graph)
{
	if (graph->rect.left <= 1212)
		graph->rect.left++;
	else
		graph->rect.left = 10;
       	sfSprite_setTextureRect(graph->back_sprite, graph->rect);
	sfRenderWindow_display(graph->win);
	sfRenderWindow_clear(graph->win, sfBlue);
	sfRenderWindow_drawSprite(graph->win, graph->back_sprite , NULL);
	sfSprite_setPosition(graph->platform_sprite, graph->platform);
	sfSprite_setPosition(graph->Robotnic_sprite1, graph->obstacle1);
	sfSprite_setScale(graph->platform_sprite, graph->setscale);
	sfRenderWindow_drawSprite(graph->win, graph->platform_sprite , NULL);
	sfClock_restart(graph->Clock);
}

int	main(int ac, char **av)
{
	sf_list	graph;

	if (is_error(ac,av, &graph) == 84)
		return (84);
	else
		init(&graph, av);
	while (sfRenderWindow_isOpen(graph.win)) {
		while (sfRenderWindow_pollEvent(graph.win, &graph.event))
			if (whatkey_ispress(&graph) == 1)
				return (1);
		time_redo(&graph);
		if (graph.timer >= 0.01)
			clock_move(&graph);
		if (graph.sanic_timer >= 0.01)
			clock_sprite(&graph);
	}
	destroy(&graph);
}
