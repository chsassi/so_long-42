/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:25:55 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/07 23:38:16 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	execute(int keycode, t_container *pContainer)
{
	handle_player_movement(keycode, pContainer);
	handle_enemy_movement(pContainer);
	handle_collectibles(pContainer);
	print_stats(pContainer);
	handle_win(pContainer);
	handle_death(pContainer);
	close_window(keycode, pContainer);
	return (1);
}

int	main(int ac, char **av)
{
	t_container	ptr;
	char		*path;

	path = NULL;
	if (ac > 1)
		path = av[1];
	if (check_args(ac, path))
	{
		init_all_innit(&ptr, path);
		if (!check_map_validity(&ptr))
			return (0);
		mlx_hook(ptr.window, KeyPress, KeyPressMask, &execute, &ptr);
		mlx_hook(ptr.window, KeyPress, KeyPressMask, &close_window, &ptr);
		mlx_hook(ptr.window, 17, 1L << 17, &quit_game, &ptr);
		mlx_key_hook(ptr.window, &execute, &ptr);
		insert_images(&ptr);
		mlx_loop_hook(ptr.mlx, &render_sprite_loop, &ptr);
		mlx_loop(ptr.mlx);
	}
}
