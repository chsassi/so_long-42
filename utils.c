/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:04:32 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/09 18:04:34 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	print_error(char *error_msg, char **mtx)
{
	if (mtx)
		free_map(mtx);
	ft_printf("Error!\n%s!\n", error_msg);
	exit (1);
}

int	element_check(char c)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
		ft_printf("Map is invalid.");
	return (0);
}
