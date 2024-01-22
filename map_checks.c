/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:06:01 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/22 17:06:02 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mtx_rows(char *mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		if (mtx[i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	valid_rows(char **mtx)
{
	int	i;
	int	mtx_len;

	i = 0;
	mtx_len = 0;
	while (mtx[mtx_len])
		mtx_len++;
	if (!check_mtx_rows(mtx[i]) || !check_mtx_rows(mtx[mtx_len]))
	{
		ft_printf("Map is invalid.");
		return (0);
	}
	return (1);
}

int	check_mtx_cols(char **mtx)
{
	int	i;
	int	mtx_len;

	i = 0;
	mtx_len = strlen_sl(mtx[i]);
	while (i < mtx_len)
	{
		if (mtx[0][i] == WALL && (mtx[mtx_len][i]) == WALL)
			return (1);
		else
			return (0);
		i++;
	}
}

int	valid_cols(char **mtx)
{
	if (!check_mtx_cols(mtx))
		return (0);
	else
		return (1);
}

int	check_rectangle(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (strlen_sl(map[i]) != cols)
		{
			ft_printf("Map is not rectangular.");
			return (0);
		}
		i++;
	}
	return (1);
}
