/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:25:55 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/10 15:56:10 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

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
		print_game_start();
		mlx_hook(ptr.window, KeyPress, KeyPressMask, &execute_game, &ptr);
		mlx_hook(ptr.window, KeyPress, KeyPressMask, &close_window, &ptr);
		mlx_hook(ptr.window, 17, 1L << 17, &quit_game, &ptr);
		mlx_key_hook(ptr.window, &execute_game, &ptr);
		insert_images(&ptr);
		mlx_loop_hook(ptr.mlx, &render_sprite_loop, &ptr);
		mlx_loop(ptr.mlx);
	}
	return (0);
}
