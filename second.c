/*
** EPITECH PROJECT, 2018
** runner
** File description:
** mehdi
*/

# include "my.h"

void	spritemove_inclock(sf_list *graph)
{
        if (graph->spacekey == 0) {
                if (graph->sanic_rect.left < 10) {
                        graph->sanic_rect.left = 10;
                        graph->sanic_rect.width = 45;
                        graph->sanic_rect.top = 20;
                }
                else if (graph->sanic_rect.left == 70) {
                        graph->sanic_rect.left = 100;
                        graph->sanic_rect.width = 45;
                        graph->sanic_rect.top = 20;
                }
                else
                {
                        graph->sanic_rect.left = 9;
                        graph->sanic_rect.width = 45;
                        graph->sanic_rect.top = 20;
                }
        }
	spritemove_inclock2(graph);
        sfClock_restart(graph->obstacle_Clock);
}

void	spritemove_inclock2(sf_list *graph)
{
	if (graph->obstacle_timer >= 0.00007)
                if (graph->Robotnic_rect1.left == 265) {
                        graph->Robotnic_rect1.left = 155;
                        graph->Robotnic_rect1.width = -55;
		}
                else if (graph->Robotnic_rect1.left == 155) {
                        graph->Robotnic_rect1.left = 220;
                        graph->Robotnic_rect1.width = -50;
                }
                else if (graph->Robotnic_rect1.left == 220) {
                        graph->Robotnic_rect1.left = 100;
                        graph->Robotnic_rect1.width = -50;
                }
                else
                {
                        graph->Robotnic_rect1.left = 265;
                        graph->Robotnic_rect1.width = -45;
                }
		obstacle_move(graph);
}

void	obstacle_move(sf_list *graph)
{
	if (graph->obstacle_timer >= 0.00000001) {
		if (graph->obstacle1.x <= 0)
			graph->obstacle1.x = 1400;
		if (graph->obstacle1.x > 0)
			graph->obstacle1.x = graph->obstacle1.x - 2;
	}
}

void	sprite_setinclock(sf_list *graph)
{
	sfSprite_setScale(graph->sanic_sprite, graph->setscale);
        sfSprite_setScale(graph->Robotnic_sprite1, graph->obstacle_scale1);
        sfSprite_setTextureRect(graph->sanic_sprite, graph->sanic_rect);
        sfSprite_setTextureRect(graph->Robotnic_sprite1, graph->Robotnic_rect1);
        sfSprite_setPosition(graph->sanic_sprite, graph->scale);
        sfSprite_setPosition(graph->Robotnic_sprite1, graph->obstacle1);
}
void	clock_sprite(sf_list *graph)
{
        placement(graph);
        graph->move = 0;
        graph->setscale.x = 3 ;
        graph->setscale.y = 3;
        graph->obstacle_scale1.x = 3;
        graph->obstacle_scale1.y = 6;
	sprite_setinclock(graph);
	spritemove_inclock(graph);
        sfRenderWindow_drawSprite(graph->win, graph->sanic_sprite , NULL);
        sfRenderWindow_drawSprite(graph->win, graph->Robotnic_sprite1 , NULL);
        sfSprite_setScale(graph->Robotnic_sprite1, graph->obstacle1);
        sfClock_restart(graph->sanic_Clock);
        vec_declaration(graph);
}
