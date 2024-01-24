/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:45:08 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/09 16:45:10 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*calculate_size(int size)
{
	int	x;
	int	*res;

	x = 32;
	 res = ft_calloc(1, sizeof(int));
	*res = size * x;
	return (res);
}

void	render_player(t_container *img)
{
	img->player[0] = mlx_xpm_file_to_image(img->window,
			"./textures/ShuttleRight.xpm",
			&img->sprite_w, &img->sprite_h);
	img->player[1] = mlx_xpm_file_to_image(img->window,
			"./textures/ShuttleUp.xpm",
			&img->sprite_w, &img->sprite_h);
	img->player[2] = mlx_xpm_file_to_image(img->window,
			"./textures/ShuttleDown.xpm",
			&img->sprite_w, &img->sprite_h);
	img->player[3] = mlx_xpm_file_to_image(img->window,
			"./textures/ShuttleLeft.xpm",
			&img->sprite_w, &img->sprite_h);
}

void	render_elements(t_container *img)
{
	img->collectible = mlx_xpm_file_to_image(img->window,
			"/textures/Fuel.xpm",
			&img->sprite_w, &img->sprite_h);
	img->enemy = mlx_xpm_file_to_image(img->window,
			"/textures/Blackhole.xpm",
			&img->sprite_w, &img->sprite_h);
	img->floor = mlx_xpm_file_to_image(img->window,
			"/textures/Floor.xpm",
			&img->sprite_w, &img->sprite_h);
	img->exit = mlx_xpm_file_to_image(img->window,
			"/textures/Earth.xpm", &img->sprite_w, &img->sprite_h);
	img->wall = mlx_xpm_file_to_image(img->window,
			"/textures/Wall.xpm",&img->sprite_w, &img->sprite_h);
}

void	check_image_element(t_container *img, int rows, int cols)
{
	if (img->map.map[rows][cols] == WALL)
		mlx_put_image_to_window(img->game, img->window,
			img->wall, rows * 32, cols * 32);
	else if (img->map.map[rows][cols] == FLOOR)
		mlx_put_image_to_window(img->game, img->window,
			img->floor,rows * 32, cols * 32);
	else if (img->map.map[rows][cols] == COLLECTIBLE)
		mlx_put_image_to_window(img->game, img->window,
			img->collectible,rows * 32, cols * 32);
	else if (img->map.map[rows][cols] == EXIT)
		mlx_put_image_to_window(img->game, img->window,
			img->exit,rows * 32, cols * 32);
	else if (img->map.map[rows][cols] == PLAYER)
		mlx_put_image_to_window(img->game, img->window,
			img->player[3],rows * 32, cols * 32);
	else if (img->map.map[rows][cols] == ENEMY)
		mlx_put_image_to_window(img->game, img->window,
			img->enemy,rows * 32, cols * 32);
}

void	insert_image(t_container *img)
{
	int rows;
	int cols;

	rows = -1;
	while(img->map.map[++rows])
	{
		cols = -1;
		while(img->map.map[rows][++cols])
			check_image_element(img, rows, cols);
	}
}
