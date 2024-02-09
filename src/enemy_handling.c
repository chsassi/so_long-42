/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:38:11 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/07 23:38:16 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bring_into_range(int (*rand)(), int range)
{
	int seed;

	seed = rand();
	while(seed > range)
		seed = seed % range;
	return (seed);
}

int	enemy_can_walk(t_container *pContainer, t_axis *enemy, int direction)
{
	if (direction == 0)
	{
		if (pContainer->map.map[enemy->y][enemy->x - 1] == FLOOR)
			return (1);
	}
	else if (direction == 1)
	{
		if (pContainer->map.map[enemy->y][enemy->x + 1] == FLOOR)
			return (1);
	}
	else if (direction == 2)
	{
		if (pContainer->map.map[enemy->y - 1][enemy->x] == FLOOR)
			return (1);
	}
	else if (direction == 3)
	{
		if (pContainer->map.map[enemy->y + 1][enemy->x] == FLOOR)
			return (1);
	}
	return (0);
}

void	update_enemeies_pos(t_container *pContainer, t_axis *enemy)
{
	int direction;

	srand(pContainer->map.seed_randomizer);
	direction = bring_into_range(&rand, 4);
	if (direction == 0 && enemy_can_walk(pContainer, enemy, direction))
	{
		pContainer->map.map[enemy->y][enemy->x] = FLOOR;
		enemy->x = enemy->x - 1;
	}
	if (direction == 1 && enemy_can_walk(pContainer, enemy, direction))
	{
		pContainer->map.map[enemy->y][enemy->x] = FLOOR;
		enemy->x = enemy->x + 1;
	}
	if (direction == 2 && enemy_can_walk(pContainer, enemy, direction))
	{
		pContainer->map.map[enemy->y][enemy->x] = FLOOR;
		enemy->y = enemy->y - 1;
	}
	if (direction == 3 && enemy_can_walk(pContainer, enemy, direction))
	{
		pContainer->map.map[enemy->y][enemy->x] = FLOOR;
		enemy->y = enemy->y + 1;
	}
	(pContainer->map.seed_randomizer)++;
}
