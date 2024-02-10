/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:05:40 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/10 16:04:49 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**mtx_alloc(int rows, int cols)
{
	int		i;
	char	**mtx;

	i = 0;
	mtx = ft_calloc(rows, sizeof(char *));
	if (!mtx)
		ft_printf("Error during row allocation.\n");
	while (i < rows)
	{
		mtx[i] = ft_calloc(cols, sizeof(char));
		if (!mtx[i])
			ft_printf("Error during col allocation.\n");
		i++;
	}
	return (mtx);
}

char	**copy_mtx(char **mtx)
{
	char	**res;
	int		rows;
	int		size;

	rows = -1;
	size = count_rows(mtx);
	res = ft_calloc(size + 1, sizeof(char *));
	if (!res)
		return (NULL);
	res[size] = NULL;
	while (mtx[++rows])
		res[rows] = ft_strdup(mtx[rows]);
	return (res);
}

void	free_mtx(char **mtx)
{
	int	i;
	int	len;

	len = count_rows(mtx);
	i = 0;
	while (i < len)
	{
		free(mtx[i]);
		mtx[i] = NULL;
		i++;
	}
	free(mtx);
}
