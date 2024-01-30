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

// int	parse_keybinds(int bind)
// {
// 	if (bind == KEY_W || bind == KEY_UP)
// 		return (0);
// 	else if (bind == KEY_S || bind == KEY_DOWN)
// 		return (1);
// 	else if (bind == KEY_A || bind == KEY_LEFT)
// 		return (2);
// 	else if (bind == KEY_D || bind == KEY_RIGHT)
// 		return (3);
// 	return (-1);
// }

// int	unlock_exit(t_container *pContainer)
// {

// 	while (pContainer->map.collectibles_count >= 0)
// 	{
// 		if (pContainer->map.map[pContainer->map.player_pos.x]
// 			[pContainer->map.player_pos.y] == COLLECTIBLE)
// 			pContainer->map.collectibles_count -= 1;
// 		if (pContainer->map.collectibles_count == 0)
// 		{
// 			// sblocca uscita nella mappa
// 		}
// 	}
// 	if (pContainer->map.map[pContainer->map.player_pos.x]
// 		[pContainer->map.player_pos.y] == EXIT)
// 	{
// 		ft_printf("You Won!");
// 		quit_game(&pContainer);
// 	}
// 	return (0);
// }

// int	check_new_input(t_container *pContainer, char** map_copy, int move)
// {
// 	/* if (pContainer->map.map[pAxis->x][pAxis->y] == WALL)
// 		return (1);
// 	// unlock_exit
// 	else if (pContainer->map.map[pAxis->x][pAxis->y] == ENEMY)
// 	{
// 		ft_printf("You Lose! Try to avoid the Blackhole!");
// 		quit_game(&pContainer); */
// }
// // }
// int	update_player_pos(t_container *pContainer,char** map_copy, int keycode)
// {
// 	if (keycode == KEY_W || keycode == KEY_UP)
// 	{
// 		/**controllo che sia attraversabile [0, C, E]*/
// 		if(check_new_input(pContainer, map_copy, 1) == 1)
// 		{
// 			/**eseguo il mov e rimuovo su map_cpy la vecchia posizione del player*/
// 			exec_on_map_cpy()
// 			pContainer->map.player_pos.y -= 1;
// 		}
// 	}
// 	else if (keycode == KEY_S || keycode == KEY_DOWN)
// 		pContainer->map.player_pos.y += 1;
// 	else if (keycode == KEY_A || keycode == KEY_LEFT)
// 		pContainer->map.player_pos.x -= 1;
// 	else if (keycode == KEY_D || keycode == KEY_RIGHT)
// 		pContainer->map.player_pos.x += 1;
// 	else if (keycode == KEY_ESC)
// 		quit_game(pContainer);
// 	return (0);
// }
