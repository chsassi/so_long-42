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
	int	*size_w;
	int	*size_h;

	size_w = calculate_size(img->sprite_w);
	size_h = calculate_size(img->sprite_h);
	img->player[0] = mlx_xpm_file_to_image(img->window,
			"/textures/ShuttleRight.xpm",
			size_w, size_h);
	img->player[1] = mlx_xpm_file_to_image(img->window,
			"/textures/ShuttleUp.xpm",
			size_w, size_h);
	img->player[2] = mlx_xpm_file_to_image(img->window,
			"/textures/ShuttleDown.xpm",
			size_w, size_h);
	img->player[3] = mlx_xpm_file_to_image(img->window,
			"/textures/ShuttleLeft.xpm",
			size_w, size_h);
}

void	render_elements(t_container *img)
{
	int	*size_w;
	int	*size_h;

	size_w = calculate_size(img->sprite_w);
	size_h = calculate_size(img->sprite_h);
	img->collectible = mlx_xpm_file_to_image(img->window,
			"/textures/Fuel.xpm",
			size_w, size_h);
	img->enemy = mlx_xpm_file_to_image(img->window,
			"/textures/Blackhole.xpm",
			size_w, size_h);
	img->floor = mlx_xpm_file_to_image(img->window,
			"/textures/Floor.xpm",
			size_w, size_h);
	img->exit = mlx_xpm_file_to_image(img->window,
			"/textures/Earth.xpm", size_w,
			size_h);
	img->wall = mlx_xpm_file_to_image(img->window,
			"/textures/Wall.xpm", size_w,
			size_h);
}

void	insert_image(t_container *img, int x, int y)
{
	int	*size_w;
	int	*size_h;

	size_w = calculate_size(img->sprite_w);
	size_h = calculate_size(img->sprite_h);
	if (img->map.map[x][y] == WALL)
		mlx_put_image_to_window(img->game, img->window,
			img->wall, *size_w,
			*size_h);
	else if (img->map.map[x][y] == FLOOR)
		mlx_put_image_to_window(img->game, img->window,
			img->floor, *size_w,
			*size_h);
	else if (img->map.map[x][y] == COLLECTIBLE)
		mlx_put_image_to_window(img->game, img->window,
			img->collectible, *size_w,
			*size_h);
	else if (img->map.map[x][y] == EXIT)
		mlx_put_image_to_window(img->game, img->window,
			img->exit, *size_w,
			*size_h);
	else if (img->map.map[x][y] == PLAYER)
		mlx_put_image_to_window(img->game, img->window,
			img->player[3], *size_w,
			*size_h);
	else if (img->map.map[x][y] == ENEMY)
		mlx_put_image_to_window(img->game, img->window,
			img->enemy, *size_w, *size_h);
}
