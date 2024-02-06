/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:52:39 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/11 18:53:03 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_movement(int keycode, t_container *pContainer)
{
	move_up(keycode, pContainer);
	move_right(keycode, pContainer);
	move_down(keycode, pContainer);
	move_left(keycode, pContainer);
}

// void	handle_enemies(t_container *pContainer)
// {
// 	/*
	
	
	
// 	*/
// }

void	handle_collectibles(t_container *pCont)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < pCont->map.collectibles_count)
	{
		x = pCont->map.player_pos.x == pCont->map.collectible_pos[i].x;
		y = pCont->map.player_pos.y == pCont->map.collectible_pos[i].y;
		if (x && y)
		{
			pCont->map.collectible_pos[i].x = -1;
			pCont->map.collectible_pos[i].y = -1;
			(pCont->map.collectibles_count)--;
			break ;
		}
		i++;
	}
	i = 0;
	free(pCont->map.collectible_pos);
	pCont->map.collectible_pos = collectibles_position(pCont->map.map, pCont);
}

void	handle_win(t_container *pCont)
{
	int	x;
	int	y;

	x = pCont->map.player_pos.x == pCont->map.exit_pos.x;
	y = pCont->map.player_pos.y == pCont->map.exit_pos.y;
	if (pCont->map.collectibles_count == 0)
		pCont->map.exit = 1;
	if (x && y)
	{
		ft_printf("YOU WON!\n");
		ft_printf("Too easy? Try to win again with less moves!\n");
		quit_game(pCont);
	}
}

void	handle_death(t_container *pCont)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < pCont->map.enemies_count)
	{
		x = pCont->map.player_pos.x == pCont->map.enemy_pos[i].x;
		y = pCont->map.player_pos.y == pCont->map.enemy_pos[i].y;
		if (x && y)
		{
			ft_printf("GAME OVER! Try to avoid the blackholes!\n");
			quit_game(pCont);
		}
		i++;
	}
}
