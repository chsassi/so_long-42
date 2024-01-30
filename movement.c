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

int	parse_keybinds(int bind)
{
	if (bind == KEY_W || bind == KEY_UP)
		return (0);
	else if (bind == KEY_S || bind == KEY_DOWN)
		return (1);
	else if (bind == KEY_A || bind == KEY_LEFT)
		return (2);
	else if (bind == KEY_D || bind == KEY_RIGHT)
		return (3);
	return (-1);
}

int	unlock_exit(t_container *pContainer, t_axis *pAxis)
{
	while (pContainer->map.collectible_count >= 0) 
	{
		if (pContainer->map.map[pAxis->x][pAxis->y] == COLLECTIBLE)
			pContainer->map.collectible_count -= 1;
		if (pContainer->map.collectible_count == 0)
		{
			// sblocca uscita nella mappa
		}
	}
	if (pContainer->map.map[pAxis->x][pAxis->y] == EXIT)
	{
		ft_printf("You Won!");
		quit_game(&pContainer);
	}
	return (0);
}

int	player_moves(t_container *pContainer, t_axis *pAxis)
{
	pAxis->x = pAxis->map.player_pos.x;
	pAxis->y = pAxis->map.player_pos.y;

	if (pContainer->map.map[pAxis->x][pAxis->y] == WALL)
		return (1);
	// unlock_exit
	else if (pContainer->map.map[pAxis->x][pAxis->y] == ENEMY)
	{
		ft_printf("You Lose! Try to avoid the Blackhole!");
		quit_game(&pContainer);
	}
}

int	update_mtx(t_container *pContainer)
{
	int		bind;
	t_axis	*tmp_pos;

	tmp_pos->x = pContainer->map.player_pos.x;
	tmp_pos->y = pContainer->map.player_pos.y;
	if (bind == KEY_D || bind == KEY_RIGHT)
		tmp_pos->y -= 1;
	else if (bind == KEY_S || bind == KEY_DOWN)
		tmp_pos->y += 1;
	else if (bind == KEY_W || bind == KEY_UP)
		tmp_pos->x -= 1;
	else if (bind == KEY_A || bind == KEY_LEFT)
		tmp_pos->x += 1;
	else if (bind == KEY_ESC)
		quit_game(pContainer);
	else
		return (0);
}

int	manage_movement(t_container *pContainer, int bind)
{
	int key;

	key = parse_keybinds(bind);
	if (key >= 0 && key <= 4) // && se sono vivo o non ho ancora tutti i c e non c'e l'exit)
	{
		// funzione che aggiorna la mappa in base alla situa;
		(pContainer->map.moves)++;
	}
}
