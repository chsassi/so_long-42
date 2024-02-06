/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:25:55 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/22 00:25:56 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	execute(int keycode, t_container *pContainer)
{
	handle_movement(keycode, pContainer);
	(pContainer->map.moves)++;
	print_stats(pContainer);
	handle_collectibles(pContainer);
	handle_win(pContainer);
	handle_death(pContainer);
	close_window(keycode, pContainer);
	return (1);
}

int	main(int ac, char **av)
{
	char		*path;
	t_container	ptr;

	path = ft_strjoin("/nfs/homes/chsassi/Desktop/Progetti/so_long/maps/", av[1]);
	if (check_args(ac, path))
	{
		init_all_innit(&ptr, path);
		if (!check_map_validity(&ptr))
			return (0);
		mlx_hook(ptr.window, KeyPress, KeyPressMask, &execute, &ptr);
		mlx_hook(ptr.window, KeyPress, KeyPressMask, &close_window, &ptr);
		mlx_hook(ptr.window, 17, 1L << 17, &quit_game, &ptr);
		mlx_key_hook(ptr.window, &execute, &ptr);
		mlx_loop_hook(ptr.mlx, &insert_images, &ptr);
		mlx_loop(ptr.mlx);
	}
}

/*TODO 
	stampare a schermo il numero di collezionabili 
				raccolti e il numero di mosse fatte
	implementare il movimento dei nemici (man math.h)

	riguardare righe e colonne
	*/