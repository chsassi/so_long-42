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

int	check_new_move(t_container *pContainer, char** map_copy, int flag)
{
	int	player_x;
	int	player_y;

	player_x = pContainer->map.player_pos.x;
	player_y = pContainer->map.player_pos.x;
	if(flag == 1)
		map_copy[player_x + 1][player_y] = map_copy[player_x][player_y];		
	else if(flag == 2)
		map_copy[player_x - 1][player_y] = map_copy[player_x][player_y];		
	else if(flag == 3)
		map_copy[player_x][player_y - 1] = map_copy[player_x][player_y];		
	else if(flag == 4)
		map_copy[player_x][player_y + 1] = map_copy[player_x][player_y];	
	if (pContainer->map.map[player_x][player_y] == WALL)
		return (0);
	return (1);
}

void handle_player_move(t_container *pContainer,char** map_copy, int flag)
{
	int player_x;
	int player_y;
	
	player_x = pContainer->map.player_pos.x;
	player_y = pContainer->map.player_pos.y;
	if(check_new_move(pContainer, map_copy, flag))
	{
		if(flag == 1)
			map_copy[player_x + 1][player_y] = map_copy[player_x][player_y];		
		else if(flag == 2)
			map_copy[player_x - 1][player_y] = map_copy[player_x][player_y];		
		else if(flag == 3)
			map_copy[player_x][player_y - 1] = map_copy[player_x][player_y];		
		else if(flag == 4)
			map_copy[player_x][player_y + 1] = map_copy[player_x][player_y];		
	}
	map_copy[player_x][player_y] = FLOOR;
	(pContainer->map.moves)++;
}

void update_player_pos(t_container *pContainer,char** map_copy, int keycode)
{
	if(keycode == KEY_W || keycode == KEY_UP)
		handle_player_move(pContainer, map_copy, 1);
	if(keycode == KEY_S || keycode == KEY_DOWN)
		handle_player_move(pContainer, map_copy, 2);
	if(keycode == KEY_A || keycode == KEY_LEFT)
		handle_player_move(pContainer, map_copy, 3);
	if(keycode == KEY_D || keycode == KEY_RIGHT)
		handle_player_move(pContainer, map_copy, 4);
	if(keycode == KEY_ESC)
		quit_game(pContainer);
}
