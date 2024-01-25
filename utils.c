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
		return (0);
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

int	count_cols(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[0][i] != '\0')
		i++;
	return (i);
}

int	count_rows(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i] != NULL)
		i++;
	return (i);
}

int		check_args(int ac, char *map_file)
{
	if (ac > 2)
		print_error(-4);
	else if (ac < 2)
		print_error(-5);
	else if (ac == 2)
	{
		if (ft_strncmp(&map_file[strlen_gnl(map_file) - 4], ".ber", 4) != 0)
			print_error(-6);
		else
			return (1);
	}
	return (0);
}



int		print_error(int error_nbr)
{
	if (error_nbr == -1)
		ft_printf("Error in map rendering (check file: smap_checks).");
	else if (error_nbr == -2)
		ft_printf("Error in element number or wrong characters in map (check file: map_checks).");
	else if (error_nbr == -3)
		ft_printf("Error. Player cannot reach an element (check file: map_handling.c).");
	else if (error_nbr == -4)
		ft_printf("Too many arguments. Run with './so_long' and a .ber file");
	else if (error_nbr == -5)
		ft_printf("Too few arguments. Run with './so_long' and a .ber file");
	else if (error_nbr == -6)
		ft_printf("Invalid file. Run with a .ber file");
	else if (error_nbr == -7)
		ft_printf("Map contains invalid/double lines.");
	return (0);
}