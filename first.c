/*
** EPITECH PROJECT, 2018
** graph
** File description:
** mehdi
*/

# include "my.h"

void	init(sf_list *graph, char **av)
{
        sfVideoMode     m = {1212.5 , 640, 32};
        char    *s = "sanic the black super hero";

        graph->win = sfRenderWindow_create(m, s, sfResize | sfClose, NULL);
        sprite_text_dec(graph);
        sfMusic_play(graph->music);
        sfMusic_setLoop(graph->music, sfTrue);
sfSprite_setTexture(graph->back_sprite, graph->back_texture, sfTrue);
sfSprite_setTexture(graph->platform_sprite, graph->platform_texture, sfTrue);
sfSprite_setTexture(graph->sanic_sprite, graph->sanic_texture, sfTrue);
sfSprite_setTexture(graph->Robotnic_sprite1, graph->Robotnic_texture1, sfTrue);
sfSprite_setTexture(graph->Robotnic_sprite2, graph->Robotnic_texture2, sfTrue);
        graph->Clock = sfClock_create();
        graph->obstacle_Clock = sfClock_create();
        graph->sanic_Clock = sfClock_create();
        rect_cut(graph);
        graph->scale.x = 2;
        graph->scale.y = 100;
        graph->obstacle1.x = 600;
        graph->obstacle1.y = 222;
}

void	time_redo(sf_list *graph)
{
	graph->sprite_x = sfSprite_getPosition(graph->sanic_sprite).x;
	graph->sprite_y = sfSprite_getPosition(graph->sanic_sprite).y;
	graph->fatdoc_x = sfSprite_getPosition(graph->Robotnic_sprite1).x;
	graph->fatdoc_y = sfSprite_getPosition(graph->Robotnic_sprite1).y;
	if (graph->sprite_x >= graph->fatdoc_x - 50 &&
	    graph->sprite_x <= graph->fatdoc_x +110
	    &&   graph->sprite_y >= graph->fatdoc_y &&
	    graph->sprite_y <= graph->fatdoc_y + 450)
		my_putstr("you died");
	graph->sanic_time = sfClock_getElapsedTime(graph->Clock);
        graph->sanic_timer = graph->time.microseconds / 1000000.0;
        graph->time = sfClock_getElapsedTime(graph->Clock);
        graph->timer = graph->time.microseconds / 1000000.0;
        graph->obstacle_time = sfClock_getElapsedTime(graph->obstacle_Clock);
        graph->obstacle_timer = graph->time.microseconds / 1000000.0;
}

void	sprite_text_dec(sf_list *graph)
{
        char    *p = "platform.png";
        char    *n = "city_background.png";
        char    *s1 = "robotnik_walk2.png";
        char    *s2 = "robotnik_walk1.png";

        graph->back_texture = sfTexture_createFromFile(n , NULL);
        graph->Robotnic_texture1 = sfTexture_createFromFile(s1 , NULL);
        graph->Robotnic_texture2 = sfTexture_createFromFile(s2 , NULL);
        graph->platform_texture = sfTexture_createFromFile(p , NULL);
        graph->sanic_texture = sfTexture_createFromFile("player.png" , NULL);
        graph->music = sfMusic_createFromFile("Batman_music.ogg");
        graph->back_sprite = sfSprite_create();
        graph->Robotnic_sprite1 = sfSprite_create();
        graph->Robotnic_sprite2 = sfSprite_create();
        graph->platform_sprite = sfSprite_create();
        graph->sanic_sprite = sfSprite_create();
sfSprite_setTexture(graph->platform_sprite, graph->platform_texture,sfTrue);
}

void	to_the_sky(sf_list *graph)
{
        if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && graph->scale.y > 2) {
                graph->scale.y -=3;
                graph->sanic_rect.left = 7;
                graph->sanic_rect.width = 45;
                graph->sanic_rect.top = 75;
                graph->sanic_rect.height = 50;
                graph->spacekey = 1;
                graph->move = 1;
        }
        else if (graph->move == 0) {
                reset_rect(graph);
        }
}

void	reset_rect(sf_list *graph)
{
        graph->spacekey = 0;
        graph->sanic_rect.left = 0;
        graph->sanic_rect.width = 55;
        graph->sanic_rect.top = 20;
        graph->sanic_rect.height = 30;
}
