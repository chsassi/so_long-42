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

void	free_images(t_container *pContainer)
{
	int	i;

	i = 0;
	while (i < 4)
		mlx_destroy_image(pContainer->mlx, pContainer->player[i++]);
	mlx_destroy_image(pContainer->mlx, pContainer->floor);
	mlx_destroy_image(pContainer->mlx, pContainer->wall);
	mlx_destroy_image(pContainer->mlx, pContainer->exit);
	mlx_destroy_image(pContainer->mlx, pContainer->collectible);
	mlx_destroy_image(pContainer->mlx, pContainer->enemy);
}

int	quit_game(t_container *pContainer)
{
	free_mtx(pContainer->map.map);
	free_images(pContainer);
	mlx_destroy_window(pContainer->mlx, pContainer->window);
	mlx_destroy_display(pContainer->mlx);
	free(pContainer->mlx);


	exit(0);
}

int	close_window(int keycode, t_container *pContainer)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("GAME CLOSED SUCCESSFULLY");
		quit_game(pContainer);
	}
	return (1);
}
