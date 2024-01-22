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
}