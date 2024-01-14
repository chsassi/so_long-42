/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_endgame.c                                  :+:      :+:    :+:   */
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

/*mettere controllo su null alle variabili degli sprite*/

void	free_images(t_container *free)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(free->game, free->player[i]);
		i++;
	}
	mlx_destroy_image(free->game, free->floor);
	mlx_destroy_image(free->game, free->wall);
	mlx_destroy_image(free->game, free->exit);
	mlx_destroy_image(free->game, free->collectible);
}

int	quit_game(t_container *quit)
{
	free_map(quit->map->map);
	free_images(quit);
	mlx_destroy_window(quit->game, quit->window);
	mlx_destroy_display(quit->game);
	free(quit->game);
	exit(0);
	return (0);
}
