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

size_t	strlen_sl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
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
	if (c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C' || c == 'N')
		return (1);
	else
	{
		ft_printf("Map is invalid.");
		return (0);
	}
}

int	check_borders(char *s)
{
	int	i;

	i = 0;
	if (element_check == 1)
		return (0);
	while (s[i])
	{
		if (s[i] != '1')
			exit (0);
		i++;
	}
	return (1);
}

int	check_walls(char *s)
{
	size_t	len;

	len = strlen_sl(s);
	if (s[0] == '1' && (s[len] - 1) == '1')
		return (1);
	else
	{
		exit (0);
		return (0);
	}
}
