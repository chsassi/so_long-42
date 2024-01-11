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

void	render_player(t_container *img)
{
	img->player[0] = mlx_xpm_file_to_image(img->window,
			"/textures/ShuttleRight.xpm",
			(32 * img->sprite_w), (32 * img->sprite_h));
	img->player[1] = mlx_xpm_file_to_image(img->window,
			"/textures/ShuttleUp.xpm",
			(32 * img->sprite_w), (32 * img->sprite_h));
	img->player[2] = mlx_xpm_file_to_image(img->window,
			"/textures/ShuttleDown.xpm",
			(32 * img->sprite_w), (32 * img->sprite_h));
	img->player[3] = mlx_xpm_file_to_image(img->window,
			"/textures/ShuttleLeft.xpm",
			(32 * img->sprite_w), (32 * img->sprite_h));
}

void	render_elements(t_container *img)
{
	img->collectible = mlx_xpm_file_to_image(img->window,
			"/textures/Fuel.xpm",
			(32 * img->sprite_w), (32 * img->sprite_h));
	img->enemy = mlx_xpm_file_to_image(img->window,
			"/textures/Blackhole.xpm",
			(32 * img->sprite_w), (32 * img->sprite_h));
	img->floor = mlx_xpm_file_to_image(img->window,
			"/textures/Floor.xpm",
			(32 * img->sprite_w), (32 * img->sprite_h));
	img->exit = mlx_xpm_file_to_image(img->window,
			"/textures/Earth.xpm", (32 * img->sprite_w),
			(32 * img->sprite_h));
}

