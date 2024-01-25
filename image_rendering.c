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

void	render_player(t_container *pContainer)
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

void	render_elements(t_container *pContainer)
{
	pContainer->enemy= mlx_xpm_file_to_image(pContainer->mlx, "/nfs/homes/chsassi/Desktop/Progetti/sl/textures/blackhole.xpm", &pContainer->sprite_h, &pContainer->sprite_w);
	pContainer->floor = mlx_xpm_file_to_image(pContainer->mlx, "/nfs/homes/chsassi/Desktop/Progetti/sl/textures/floor.xpm", &pContainer->sprite_h, &pContainer->sprite_w);
	pContainer->exit = mlx_xpm_file_to_image(pContainer->mlx, "./textures/earth.xpm", &pContainer->sprite_h, &pContainer->sprite_w);
	pContainer->wall = mlx_xpm_file_to_image(pContainer->mlx, "./textures/wall.xpm",&pContainer->sprite_h, &pContainer->sprite_w);
}

void	check_image_element(t_container *pContainer, int rows, int cols)
{
	if (pContainer->map.map[rows][cols] == WALL)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window, pContainer->wall, rows * 32, cols * 32);
	else if (pContainer->map.map[rows][cols] == FLOOR)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window, pContainer->floor,rows * 32, cols * 32);
	else if (pContainer->map.map[rows][cols] == COLLECTIBLE)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window, pContainer->collectible,rows * 32, cols * 32);
	else if (pContainer->map.map[rows][cols] == EXIT)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window, pContainer->exit,rows * 32, cols * 32);
	else if (pContainer->map.map[rows][cols] == PLAYER)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window, pContainer->player[3],rows * 32, cols * 32);
	else if (pContainer->map.map[rows][cols] == ENEMY)
		mlx_put_image_to_window(pContainer->mlx, pContainer->window, pContainer->enemy,rows * 32, cols * 32);
}

int	insert_image(t_container *pContainer)
{
	int rows;
	int cols;

	rows = -1;
	while(pContainer->map.map[++rows])
	{
		cols = -1;
		while(pContainer->map.map[rows][++cols])
			check_image_element(pContainer, rows, cols);
	}
	return (0);
}
