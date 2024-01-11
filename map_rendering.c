/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:52:27 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/11 18:52:28 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_images_to_window(t_container *img, int x, int y)
{
	if (img->map.map[y][x] == '1')
		mlx_put_image_to_window(img->game, img->window, img->wall, ());
	else if (img->map.map[y][x] == '0')
		mlx_put_image_to_window(img->game, img->floor, img->wall, ());
	else if (img->map.map[y][x] == 'C')
		mlx_put_image_to_window(img->game, img->collectible, img->wall, ());
	else if (img->map.map[y][x] == 'E')
		mlx_put_image_to_window(img->game, img->exit, img->wall, ());
	else if (img->map.map[y][x] == 'P')
		mlx_put_image_to_window(img->game, img->floor, img->player[0], ());
}
