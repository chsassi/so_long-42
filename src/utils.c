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

int	check_elem_number(char **map)
{
	int	player_nbr;
	int	exit_nbr;

	player_nbr = count_elements(map, PLAYER);
	exit_nbr = count_elements(map, EXIT);
	if (player_nbr != 1 || exit_nbr != 1)
		return (0);
	return (1);
}

int	print_error(int error_nbr)
{
	if (error_nbr == -1)
		ft_printf("ERROR!\n Map rendering error. Check file map_handling\n");
	else if (error_nbr == -2)
		ft_printf("ERROR!\n Invalid characters. Check file map_handling\n");
	else if (error_nbr == -3)
		ft_printf("ERROR!\n Element not reachable. Check file map_handling\n");
	else if (error_nbr == -4)
		ft_printf("Too many arguments. Run with './so_long' and a .ber file");
	else if (error_nbr == -5)
		ft_printf("Too few arguments. Run with './so_long' and a .ber file");
	else if (error_nbr == -6)
		ft_printf("Invalid file. Run with a .ber file");
	else if (error_nbr == -7)
		ft_printf("Map contains invalid/double lines. Check parsing file\n");
	return (0);
}
