/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:14:56 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/10 15:56:10 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_axis	player_position(char **mtx)
{
	t_axis	player_pos;
	int		rows;
	int		cols;

	rows = 0;
	while (mtx[rows] != NULL)
	{
		cols = 0;
		while (mtx[rows][cols] != '\0')
		{
			if (mtx[rows][cols] == 'P')
			{
				player_pos.x = cols;
				player_pos.y = rows;
			}
			cols++;
		}
		rows++;
	}
	return (player_pos);
}

t_axis	exit_potision(char **mtx)
{
	t_axis	exit_pos;
	int		rows;
	int		cols;

	rows = 0;
	while (mtx[rows] != NULL)
	{
		cols = 0;
		while (mtx[rows][cols] != '\0')
		{
			if (mtx[rows][cols] == EXIT)
			{
				exit_pos.x = cols;
				exit_pos.y = rows;
			}
			cols++;
		}
		rows++;
	}
	return (exit_pos);
}

t_axis	*collectibles_position(char **mtx, t_container *pContainer)
{
	t_axis	*collectibles_pos;
	int		rows;
	int		cols;
	int		collectible_nbr;
	int		i;

	rows = -1;
	i = 0;
	collectible_nbr = count_elements(mtx, COLLECTIBLE);
	pContainer->map.collectibles_count = collectible_nbr;
	collectibles_pos = ft_calloc(collectible_nbr, sizeof(t_axis));
	if (collectibles_pos == NULL)
		free(collectibles_pos);
	while ((i < collectible_nbr) && mtx[++rows] != NULL)
	{
		cols = -1;
		while (mtx[rows][++cols] != '\0')
		{
			if (mtx[rows][cols] == COLLECTIBLE)
				collectibles_pos[i].x = cols;
			if (mtx[rows][cols] == COLLECTIBLE)
				collectibles_pos[i++].y = rows;
		}
	}
	return (collectibles_pos);
}

t_axis	*enemies_position(char **mtx, t_container *pContainer)
{
	t_axis	*enemy_pos;
	int		rows;
	int		cols;
	int		enemy_nbr;
	int		i;

	rows = -1;
	i = 0;
	enemy_nbr = count_elements(mtx, ENEMY);
	pContainer->map.enemies_count = enemy_nbr;
	enemy_pos = ft_calloc(enemy_nbr, sizeof(t_axis));
	if (enemy_pos == NULL)
		free_position(pContainer);
	while (i < enemy_nbr && mtx[++rows] != NULL)
	{
		cols = -1;
		while (mtx[rows][++cols] != '\0')
		{
			if (mtx[rows][cols] == ENEMY)
				enemy_pos[i].x = cols;
			if (mtx[rows][cols] == ENEMY)
				enemy_pos[i++].y = rows;
		}
	}
	return (enemy_pos);
}
