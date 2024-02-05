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

int	main(int ac, char** av)
{
	char		*path;
	t_container	pContainer;

	path = ft_strjoin("maps/", av[1]);
	if (check_args(ac, path))
	{
		init_all_innit(&pContainer, path);
		if(!check_map_validity(&pContainer))
			return 0;
		mlx_hook(pContainer.window, KeyPress, KeyPressMask, &execute, &pContainer);
		mlx_hook(pContainer.window, KeyPress, KeyPressMask, &close_window, &pContainer);
		mlx_hook(pContainer.window, 17, 1L << 17, &quit_game, &pContainer);
		mlx_key_hook(pContainer.window, &execute, &pContainer);
		mlx_loop_hook(pContainer.mlx, &insert_images, &pContainer);
		mlx_loop(pContainer.mlx);
	}
}


/*TODO 
	stampare a schermo il numero di collezionabili raccolti e il numero di mosse fatte
	implementare il movimento dei nemici (man math.h)
	
	riguardare righe e colonne (lo fa chri)
	*/