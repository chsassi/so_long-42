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

void	init_map(t_map *map)
{
	map->map = NULL;
	map->moves = 0;
	map->exit = 0;
	map->rows = 0;
	map->cols = 0;
	map->collectibles = 0;
	map->player_pos.x = 0;
	map->player_pos.y = 0;
	map->moves = 0;
	map->exit = 0;
}
void	init_container(t_container *vars)
{
	vars->window_w = 0;
	vars->window_h = 0;
	vars->floor = NULL;
	vars->wall = NULL;
	vars->exit = NULL;
	vars->player[0] = NULL;
	vars->player[1] = NULL;
	vars->player[2] = NULL;
	vars->player[3] = NULL;
	vars->enemy = NULL;
	vars->collectible = NULL;
	vars->sprite_w = 32;
	vars->sprite_h = 32;
}

void	init_elements(char **mtx, t_container *vars)
{
	vars->map.player_pos = player_position(mtx);
	vars->map.exit_pos = exit_potision(mtx);
	vars->map.collectible_pos = collectibles_position(mtx, vars);
	vars->map.enemy_pos = enemies_position(mtx, vars);
}

void	init_window(t_container *init)
{
	init->game = mlx_init();
	if (!init->game)
		return ;
	init->game = mlx_new_window(init->game, (init->sprite_w),
			(init->sprite_h), "so_long");
}
void init_all_innit(t_container *var_container)
{
	init_container(var_container);
	init_map(&var_container->map);
	//t_map_init(var_container->map.map, var_container);
	//init_window(var_container);
}
