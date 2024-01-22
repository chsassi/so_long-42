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




int	main(int ac, char **av)
{
	char		*path;
	char		**mtx;
	t_container	*vars;

	path = av[1];
	vars = malloc(sizeof(t_container));
	init_all_innit(vars);
	if (check_args(ac, path) == 1)
	{
		mtx = get_mtx(&vars->map, path);
		t_map_init(mtx, vars);
		/* poi scorriamo la mtx e assegnami i valori a t_map
		 scorriamo la matrice e  controllare che sia una mappa valida
		*/
		init_window(vars);
	}
}
