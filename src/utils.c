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

int	check_args(int ac, char *map_file)
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

int	print_error(int error_nbr)
{
	if (error_nbr == -1)
		ft_printf("ERROR!\nMap rendering error. Check file map_handling\n");
	else if (error_nbr == -2)
		ft_printf("ERROR!\nInvalid characters. Check file map_handling\n");
	else if (error_nbr == -3)
		ft_printf("ERROR!\nElement not reachable. Check file map_handling\n");
	else if (error_nbr == -4)
		ft_printf("Too many arguments.\nRun with './so_long' and a .ber file");
	else if (error_nbr == -5)
		ft_printf("Too few arguments.\nRun with './so_long' and a .ber file");
	else if (error_nbr == -6)
		ft_printf("Invalid file.\nRun with a .ber file");
	else if (error_nbr == -7)
		ft_printf("Map contains invalid/double lines. Check parsing file\n");
	return (0);
}

void	print_stats(t_container *pContainer)
{
	mlx_string_put(pContainer->mlx, pContainer->window,
		5, pContainer->map.rows * pContainer->sprite_w + (EXTRA_WIN / 2),
		0xFFFFFF, "Moves: ");
	mlx_string_put(pContainer->mlx, pContainer->window,
		45, pContainer->map.rows * pContainer->sprite_w + (EXTRA_WIN / 2),
		0xFFFFFF, ft_itoa(pContainer->map.moves));
	mlx_string_put(pContainer->mlx, pContainer->window,
		45, pContainer->map.rows * pContainer->sprite_w + (EXTRA_WIN / 2),
		0xFFFFFF, "0");
	mlx_string_put(pContainer->mlx, pContainer->window,
		pContainer->map.cols * pContainer->sprite_w + (EXTRA_WIN / 2), 45,
		0xFFFFFF, "Fuel Tanks:");
	mlx_string_put(pContainer->mlx, pContainer->window,
		pContainer->map.cols * pContainer->sprite_w + (EXTRA_WIN / 2), 5,
		0xFFFFFF, ft_itoa(pContainer->map.collectibles_count));
}

void	print_game_start()
{
	ft_printf("Welcome to so_long!\n");
	ft_printf("Collect all the fuel tanks and get back to Earth!\n");
	ft_printf("Be carful, there are blackholes around. Avoid them.\n\n");
}
