/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:04:11 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/11 18:53:32 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_images(t_container *pContainer)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(pContainer->mlx, pContainer->player[i]);
		i++;
	}
	mlx_destroy_image(pContainer->mlx, pContainer->floor);
	mlx_destroy_image(pContainer->mlx, pContainer->wall);
	mlx_destroy_image(pContainer->mlx, pContainer->exit);
	mlx_destroy_image(pContainer->mlx, pContainer->collectible);
}

int	quit_game(t_container *pContainer)
{
	free_map(pContainer->map.map);
	free_images(pContainer);
	mlx_destroy_window(pContainer->mlx, pContainer->window);
	mlx_destroy_display(pContainer->mlx);
	free(pContainer->mlx);
	exit(0);
}
