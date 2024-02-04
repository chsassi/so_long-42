/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:05:40 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/01 20:13:14 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**mtx_alloc(char **mtx, int rows, int cols)
{
	int	i;

	i = 0;
	mtx = (char**)malloc(rows * sizeof(char*));
	if (!mtx)
		ft_printf("Error during row allocation.\n");
	while (i < rows)
	{
		mtx[i] = (char *)malloc(cols * sizeof(char));
		if (!mtx[i])
			ft_printf("Error during col allocation.\n");
		i++;
	}
	return (mtx);
}

char	**copy_mtx(char** mtx)
{
	char** res;
	int rows;

	rows = -1;
	res = (char **)ft_calloc(count_rows(mtx) , sizeof(char*));
	while(mtx[++rows])
	{
		res[rows] = ft_strdup(mtx[rows]);
	}
/* 	int i = 0;
	while(i < count_rows(mtx))
	{
		printf("%s", mtx[i++]);
		printf("\n");
	} */
	return (res);
}

void	free_mtx(char **mtx)
{
	int	i;
	int len;

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