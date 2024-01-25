/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:13:25 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/21 21:13:27 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *pMap)
{
	pMap->map = NULL;
	pMap->moves = 0;
	pMap->exit = 0;
	pMap->rows = 0;
	pMap->cols = 0;
	pMap->collectibles = 0;
	pMap->player_pos.x = 0;
	pMap->player_pos.y = 0;
	pMap->moves = 0;
	pMap->exit = 0;
	pMap->enemies = 0;
	pMap->enemies_count = 0;
}
void	init_container(t_container *pContainer)
{
	pContainer->window_w = 1920;
	pContainer->window_h = 1080;
	pContainer->floor = NULL;
	pContainer->wall = NULL;
	pContainer->exit = NULL;
	pContainer->player[0] = NULL;
	pContainer->player[1] = NULL;
	pContainer->player[2] = NULL;
	pContainer->player[3] = NULL;
	pContainer->enemy = NULL;
	pContainer->collectible = NULL;
	pContainer->sprite_w = 32;
	pContainer->sprite_h = 32;
}

void init_all_innit(t_container *pContainer, char* path)
{
	char **tmp_mtx;

	
	tmp_mtx = get_mtx(path);
	init_container(pContainer);
	init_map(&pContainer->map);
	pContainer->map.map = tmp_mtx;
	init_element_position(pContainer->map.map, pContainer);
	pContainer->mlx = mlx_init();
	pContainer->window = mlx_new_window(pContainer->mlx, pContainer->map.cols * pContainer->sprite_h,
	pContainer->map.rows * pContainer->sprite_w , "so_long");	
	if (!pContainer->window)
		return ;
}
