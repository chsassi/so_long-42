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
	while (mtx && mtx[i])
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
	while (mtx[i] && mtx[mtx_len])
	{
		if (strlen_gnl(mtx[i]) != strlen_gnl(mtx[mtx_len]))
			return (0);
		i++;
		mtx_len--;
	}
	if (!check_mtx_rows(mtx[i]) || !check_mtx_rows(mtx[mtx_len]))
		return (0);
	return (1);
}

int	check_mtx_cols(char **mtx)
{
	int	i;
	int	len;
	int	mtx_len;

	i = 0;
	len = 0;
	while (mtx[len])
		len++;
	mtx_len = strlen_gnl(mtx[i]);
	while (i < mtx_len)
	{
		if (mtx[0][i] == WALL && (mtx[len - 1][i]) == WALL)
			return (1);
		i++;
	}
	return (0);
}

int	valid_cols(char **mtx)
{
	if (!check_mtx_cols(mtx))
		return (0);
	return (1);
}

int	check_rectangle(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (strlen_gnl(map[i]) != cols)
			return (0);
		i++;
	}
	return (1);
}
