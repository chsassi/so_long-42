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

void	render_player_image(t_container *pContainer)
{
	pContainer->player[0] = mlx_xpm_file_to_image(pContainer->mlx,
			"./textures/shuttleright.xpm",
			&pContainer->sprite_w, &pContainer->sprite_h);
	pContainer->player[1] = mlx_xpm_file_to_image(pContainer->mlx,
			"./textures/shuttleup.xpm",
			&pContainer->sprite_w, &pContainer->sprite_h);
	pContainer->player[2] = mlx_xpm_file_to_image(pContainer->mlx,
			"./textures/shuttledown.xpm",
			&pContainer->sprite_w, &pContainer->sprite_h);
	pContainer->player[3] = mlx_xpm_file_to_image(pContainer->mlx,
			"./textures/shuttleleft.xpm",
			&pContainer->sprite_w, &pContainer->sprite_h);
}

void	render_element_image(t_container *pContainer)
{
	pContainer->collectible = mlx_xpm_file_to_image(pContainer->mlx,
			"./textures/fuel.xpm",
			&pContainer->sprite_h, &pContainer->sprite_w);
	pContainer->enemy = mlx_xpm_file_to_image(pContainer->mlx,
			"./textures/blackhole.xpm",
			&pContainer->sprite_h, &pContainer->sprite_w);
	pContainer->floor = mlx_xpm_file_to_image(pContainer->mlx,
			"./textures/floor.xpm",
			&pContainer->sprite_h, &pContainer->sprite_w);
	pContainer->exit = mlx_xpm_file_to_image(pContainer->mlx,
			"./textures/earth.xpm",
			&pContainer->sprite_h, &pContainer->sprite_w);
	pContainer->wall = mlx_xpm_file_to_image(pContainer->mlx,
			"./textures/wall.xpm",
			&pContainer->sprite_h, &pContainer->sprite_w);
}

void	render_sprite_on_mtx(t_container *pContainer, int rows, int cols)
{
	if (pContainer->map.map[rows][cols] == WALL)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window,
			pContainer->wall, cols * 32, rows * 32);
	else if (pContainer->map.map[rows][cols] == FLOOR)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window,
			pContainer->floor, cols * 32, rows * 32);
	else if (pContainer->map.map[rows][cols] == COLLECTIBLE)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window,
			pContainer->collectible, cols * 32, rows * 32);
	else if (pContainer->map.map[rows][cols] == EXIT)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window,
			pContainer->exit, cols * 32, rows * 32);
	else if (pContainer->map.map[rows][cols] == PLAYER)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window,
			pContainer->player[3], cols * 32, rows * 32);
	else if (pContainer->map.map[rows][cols] == ENEMY)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window,
			pContainer->enemy, cols * 32, rows * 32);
}

int	render_sprite_loop(t_container *pContainer)
{
	int	rows;
	int	cols;

	rows = -1;
	while (pContainer->map.map[++rows])
	{
		cols = -1;
		while (pContainer->map.map[rows][++cols])
			render_sprite_on_mtx(pContainer, rows, cols);
	}
	return (0);
}

int	insert_images(t_container *pContainer)
{
/* 	if (pContainer->map.exit == 1)
		pContainer->map.map[pContainer->map.exit_pos.y]
		[pContainer->map.exit_pos.x] = EXIT;
	else
		pContainer->map.map[pContainer->map.exit_pos.y][pContainer->map.exit_pos.x] = FLOOR; */
	render_player_image(pContainer);
	render_element_image(pContainer);
	render_sprite_loop(pContainer);
	return (0);
}
