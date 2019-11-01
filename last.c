/*
** EPITECH PROJECT, 2018
** graph
** File description:
** last
*/

# include "my.h"

int	whatkey_ispress(sf_list *graph)
{
        if (graph->event.type == sfEvtClosed) {
                destroy(graph);
                return (1);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
                destroy(graph);
                return (1);
        }
}

void	placement(sf_list *graph)
{
        to_the_sky(graph);
        to_hell(graph);
        if (sfKeyboard_isKeyPressed(sfKeyLeft)
	    == sfTrue && graph->scale.x >= 1) {
                graph->spacekey = 1;
                graph->move = 1;
                graph->sanic_rect.left = 55;
                graph->sanic_rect.width = -55;
                graph->sanic_rect.top = 20;
                graph->sanic_rect.height = 30;
                graph->scale.x -=5;
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight)
	    == sfTrue && graph->scale.x <= 1170) {
                graph->move = 1;
                graph->scale.x +=5;
        }
        else if (graph->move == 0)
                reset_rect(graph);
        graph->spacekey = 1;
}

void	destroy(sf_list *graph)
{
        sfRenderWindow_close(graph->win);
        sfMusic_stop(graph->music);
        sfSprite_destroy(graph->back_sprite);
        sfSprite_destroy(graph->Robotnic_sprite1);
        sfSprite_destroy(graph->Robotnic_sprite2);
        sfSprite_destroy(graph->sanic_sprite);
        sfSprite_destroy(graph->platform_sprite);
	sfMusic_destroy(graph->music);
        sfTexture_destroy(graph->back_texture);
        sfTexture_destroy(graph->Robotnic_texture1);
 	sfTexture_destroy(graph->Robotnic_texture2);
	sfTexture_destroy(graph->platform_texture);
	sfTexture_destroy(graph->sanic_texture);
	sfClock_destroy(graph->Clock);
	sfClock_destroy(graph->sanic_Clock);
	sfRenderWindow_destroy(graph->win);
}

int	is_flag(int ac, char **av)
{
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
                my_putstr("good luck\n");
		return (1);
	}
	return (0);
}
