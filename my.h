/*
** EPITECH PROJECT, 2017
** runner
** File description:
** h
*/

#ifndef MY_H_
# define MY_H_

#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>

typedef struct s_list
{
	int		lost1;
	int		yaxis;
	int		xaxis;
	int		move;
	int		obstacle1_x;
	int		obstacle1_y;
	int		obstacle2_x;
	int		obstacle2_y;
	int		spacekey;
	int		sprite_x;
	int		sprite_y;
	int		fatdoc_x;
	int		fatdoc_y;
	float           x,y;
	sfVector2f      scale;
	sfVector2f      setscale;
	sfVector2f      obstacle1;
	sfVector2f      obstacle_scale1;
	sfVector2f      platform;
	sfVector2f      obstacle2;
        sfVideoMode   mode;
        sfRenderWindow* win;
	sfTexture*      back_texture;
	sfTexture*      Robotnic_texture1;
	sfTexture*      Robotnic_texture2;
	sfTexture*      platform_texture;
        sfTexture*      sanic_texture;
        sfTexture*      gameovere_texture;
	sfSprite*       back_sprite;
	sfSprite*       Robotnic_sprite1;
	sfSprite*       Robotnic_sprite2;
	sfSprite*       platform_sprite;
        sfSprite*       over_sprite;
        sfSprite*       sanic_sprite;
	sfIntRect       rect;
	sfIntRect       sanic_rect;
	sfIntRect       Robotnic_rect1;
	sfIntRect       Robotnic_rect2;
        sfEvent         event;
        sfTime          time;
	sfTime          sanic_time;
	sfTime          obstacle_time;
        sfClock*        Clock;
	float           timer;
	float           obstacle_timer;
	sfClock*        sanic_Clock;
	sfClock*        obstacle_Clock;
        float           sanic_timer;
        sfMusic*        music;
        sfMusic*        hit;
	sfMusic*        lost;
        int             nb;
	char		*map;
}sf_list;

void	init(sf_list *graph, char **av);
void	getlengh(char *vuff, sf_list *graph);
void	spritemove_inclock(sf_list *graph);
void	spritemove_inclock2(sf_list *graph);
void	destroy(sf_list *graph);
int	check_file(char *str);
void	obstacle_move(sf_list *graph);
int	is_error(int ac, char **av, sf_list *graph);
void	to_the_sky(sf_list *graph);
void	to_hell(sf_list *graph);
void	rect_cut(sf_list *graph);
void	sprite_text_dec(sf_list *graph);
void	reset_rect(sf_list *graph);
int	whatkey_ispress(sf_list *graph);
void	sprite_settinclock(sf_list *graph);
void	vec_declaration(sf_list	*graph);
void	placement(sf_list *graph);
void	clock_sprite(sf_list *graph);
void	time_redo(sf_list *graph);
void	my_putchar(char c);
int	my_putstr(char *str);
int	is_flag(int ac, char **av);
int	main(int ac, char **av);

# endif /* MY_H_ */
