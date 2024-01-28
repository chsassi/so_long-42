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

int	update_mtx(t_container *pContainer)
{
	int		bind;
	t_axis	*tmp_pos;

	tmp_pos->x = pContainer->map.player_pos.x;
	tmp_pos->y = pContainer->map.player_pos.y;
	if (parse_keybinds(KEY_RIGHT) || parse_keybinds(KEY_D))
		tmp_pos->y -= 1;
	else if (parse_keybinds(KEY_LEFT) || parse_keybinds(KEY_A))
		tmp_pos->y += 1;
	else if (parse_keybinds(KEY_UP) || parse_keybinds(KEY_W))
		tmp_pos->x -= 1;
	else if (parse_keybinds(KEY_DOWN) || parse_keybinds(KEY_S))
		tmp_pos->x += 1;
	else if (parse_keybinds(KEY_ESC))
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
