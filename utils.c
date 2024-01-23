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

int	check_element(char c)
{
	if (c == PLAYER || c == COLLECTIBLE || c == ENEMY || c == EXIT
		|| c == FLOOR || c == WALL)
		return (1);
	else
	{
		ft_printf("Map is invalid.");
		return (0);
	}
}

int		count_elements(char **mtx, char c)
{
	int		rows;
	int		cols;
	int		element_nbr;

	rows = 0;
	element_nbr = 0;
	while(mtx[rows] != NULL)
	{
		cols = 0;
		while(mtx[rows][cols] != '\0')
		{
			if (mtx[rows][cols] == c)
				element_nbr++;
			cols++;
		}
		rows++;
	}
	return (element_nbr);
}


int	strlen_sl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i])
		i++;
	return (i);
}

int		check_args(int ac, char *map_file)
{
	if (ac > 2)
		ft_printf("Too many arguments. Run with './so_long' and a .ber file");
	else if (ac < 2)
		ft_printf("Too few arguments. Run with './so_long' and a .ber file");
	else if (ac == 2)
	{
		if (ft_strncmp(&map_file[strlen_sl(map_file) - 4], ".ber", 4) != 0)
			ft_printf("Invalid file. Run with a .ber file");
		else
			return (1);
	}
	return (0);
}