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

int	is_walkable(int keycode, t_container *pContainer)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		if(pContainer->map.map[pContainer->map.player_pos.y - 1][pContainer->map.player_pos.x] == WALL)
			return (0); 
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		if(pContainer->map.map[pContainer->map.player_pos.y][pContainer->map.player_pos.x - 1] == WALL)
			return (0); 
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		if(pContainer->map.map[pContainer->map.player_pos.y + 1][pContainer->map.player_pos.x] == WALL)
			return (0); 
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		if(pContainer->map.map[pContainer->map.player_pos.y][pContainer->map.player_pos.x + 1] == WALL)
			return (0); 
	}
	return (1);
}

void update_coll_info(t_container *pCont)
{
	int i;
	int x;
	int y;

	i = 0;
	while(i < pCont->map.collectibles_count)
	{
		x = pCont->map.player_pos.x == pCont->map.collectible_pos[i].x;
		y = pCont->map.player_pos.y == pCont->map.collectible_pos[i].y;
		if(x && y)
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
			ft_printf("YOU LOSE! Try to avoid the Blackhole!\n");
			quit_game(pCont);
		}
		i++;
	}
}

void	unlock_exit(t_container *pCont)
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
		quit_game(pCont);
	}
}

void	update_player_pos(int keycode, t_container *pCont)
{
	if ((keycode == KEY_W || keycode == KEY_UP) && is_walkable(keycode, pCont))
	{
		pCont->map.map[pCont->map.player_pos.y][pCont->map.player_pos.x] = FLOOR;
		pCont->map.player_pos = (t_axis){pCont->map.player_pos.x, pCont->map.player_pos.y - 1};
		pCont->map.player_direction = 1;
	}
	if ((keycode == KEY_A || keycode == KEY_LEFT) && is_walkable(keycode, pCont))
	{
		pCont->map.map[pCont->map.player_pos.y][pCont->map.player_pos.x] = FLOOR;
		pCont->map.player_pos = (t_axis){pCont->map.player_pos.x - 1, pCont->map.player_pos.y};
		pCont->map.player_direction = 3;
	}
	if ((keycode == KEY_S || keycode == KEY_DOWN) && is_walkable(keycode, pCont))
	{
		pCont->map.map[pCont->map.player_pos.y][pCont->map.player_pos.x] = FLOOR;
		pCont->map.player_pos = (t_axis){pCont->map.player_pos.x, pCont->map.player_pos.y + 1};
		pCont->map.player_direction = 2;
	}
	if ((keycode == KEY_D || keycode == KEY_RIGHT) && is_walkable(keycode, pCont))
	{
		pCont->map.map[pCont->map.player_pos.y][pCont->map.player_pos.x] = FLOOR;
		pCont->map.player_pos = (t_axis){pCont->map.player_pos.x + 1, pCont->map.player_pos.y};
		pCont->map.player_direction = 0;
	}
}
