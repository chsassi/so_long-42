/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:06:01 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/07 23:38:16 by chsassi          ###   ########.fr       */
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
	if (!check_mtx_rows(mtx[i]) || !check_mtx_rows(mtx[mtx_len - 1]))
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
	mtx_len = count_cols(mtx);
	while (i < len)
	{
		if (mtx[i][0] != WALL || (mtx[i][mtx_len - 1]) != WALL)
			return (0);
		i++;
	}
	return (1);
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
