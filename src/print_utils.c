/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:56:07 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/10 15:56:10 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(t_error error_type)
{
	if (error_type == INVALID_RENDER)
		ft_printf("Error!\nMap rendering error. Check file map_handling\n");
	else if (error_type == INVALID_CHARS)
		ft_printf("Error!\nInvalid characters. Check file map_handling\n");
	else if (error_type == INVALID_REACHABILITY)
		ft_printf("Error!\nElement not reachable. Check file map_handling\n");
	else if (error_type == INVALID_ARGS)
		ft_printf("Error!\nToo many arguments.\n\
			Run with './so_long' and a .ber file");
	else if (error_type == INVALID_ARGS2)
		ft_printf("Error!\nToo few arguments.\n\
			Run with './so_long' and a .ber file");
	else if (error_type == INVALID_FORMAT)
		ft_printf("Error!\nInvalid file.\nRun with a .ber file");
	else if (error_type == INVALID_PARSING)
		ft_printf("Error!\nMap is invalid/double lines. Check parsing file\n");
	else if (error_type == INVALID_SCREEN_SIZE)
		ft_printf("Error!\nScreen size is invalid\n");
	return (0);
}

void	print_stats(t_container *pContainer)
{
	char	*nm;
	char	*nc;
	char	*moves;
	char	*collectibles;

	nm = ft_itoa(pContainer->map.moves);
	moves = ft_strjoin("Moves: ", nm);
	mlx_put_image_to_window(pContainer->mlx, pContainer->window,
		pContainer->pixel_reset, 40,
		pContainer->map.rows * pContainer->sprite_h);
	mlx_string_put(pContainer->mlx, pContainer->window,
		5, pContainer->map.rows * pContainer->sprite_h + (EXTRA_WIN / 2),
		0xFFFFFF, moves);
	free(nm);
	free(moves);
	nc = ft_itoa(pContainer->map.collectibles_count);
	collectibles = ft_strjoin("Fuel Tanks: ", nc);
	mlx_put_image_to_window(pContainer->mlx, pContainer->window,
		pContainer->pixel_reset, 185,
		pContainer->map.rows * pContainer->sprite_h);
	mlx_string_put(pContainer->mlx, pContainer->window,
		120, pContainer->map.rows * pContainer->sprite_h + (EXTRA_WIN / 2),
		0xFFFFFF, collectibles);
	free(nc);
	free(collectibles);
}

void	print_game_start(void)
{
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ft_printf("	Welcome to so_long!\n");
	ft_printf("Collect all the fuel tanks and get back to Earth!\n");
	ft_printf("Be careful, there are blackholes around.\n");
	ft_printf("Avoid them or you could be absorbed!\n");
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
