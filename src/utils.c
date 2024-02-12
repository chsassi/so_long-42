/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:04:32 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/10 15:56:10 by chsassi          ###   ########.fr       */
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
	int	collectible_nbr;

	player_nbr = count_elements(map, PLAYER);
	exit_nbr = count_elements(map, EXIT);
	collectible_nbr = count_elements(map, COLLECTIBLE);
	if (player_nbr != 1 || exit_nbr != 1 || collectible_nbr < 1)
		return (0);
	return (1);
}

int	check_args(int ac, char *map_file)
{
	if (ac > 2)
		print_error(INVALID_ARGS);
	else if (ac < 2)
		print_error(INVALID_ARGS2);
	else if (ac == 2)
	{
		if (strlen_gnl(map_file) < 4
			|| ft_strncmp(&map_file[strlen_gnl(map_file) - 4], ".ber", 4) != 0
			|| open(map_file, O_RDONLY) == -1)
			print_error(INVALID_FORMAT);
		else
			return (1);
	}
	return (0);
}

void	assign_exit(t_container *pContainer)
{
	if (pContainer->map.exit == 1)
	{
		pContainer->map.map[pContainer->map.exit_pos.y]
		[pContainer->map.exit_pos.x] = EXIT;
	}
	else
		pContainer->map.map[pContainer->map.exit_pos.y]
		[pContainer->map.exit_pos.x] = FLOOR;
}
