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

/* void ft_print_structs(t_container	*vars)
{
	int i;

	i = 0;
	printf("map rows : %i\n", vars->map.rows);
	printf("map cols: %i\n", vars->map.cols);
	printf("map moves: %i\n", vars->map.moves);
	printf("map collectibles: %i\n", vars->map.collectibles);
	printf("map exit: %i\n", vars->map.exit);
	printf("map enemies: %i\n", vars->map.enemies);
	printf("map player.x: %i\n", vars->map.player_pos.x);
	printf("map player.y: %i\n", vars->map.player_pos.y);
	printf("exit pos.x: %i\n", vars->map.exit_pos.x);
	printf("exit pos.y: %i\n", vars->map.exit_pos.y);
	while(i < vars->map.collectibles_count)
	{
		printf("collectible pos.x: %i\n", vars->map.collectible_pos[i].x);
		printf("collectible pos.y: %i\n", vars->map.collectible_pos[i].y);
		i++;
	}
	i = 0;
	while(i < vars->map.enemies_count)
	{
		printf("enemy pos.x: %i\n", vars->map.enemy_pos[i].x);
		printf("enemy pos.y: %i\n", vars->map.enemy_pos[i].y);
		i++;
	}
} */
 
int	main(int ac, char** av)
{
	char		*map_name;
	char		*path;
	t_container	pContainer;


	map_name = av[1];
	path = ft_strjoin("maps/", map_name);
	init_all_innit(&pContainer);
	if (check_args(ac, path))
	{
		get_mtx(&pContainer.map, path);
		init_element_position(pContainer.map.map, &pContainer);
		pContainer.mlx = mlx_init();
		pContainer.window = mlx_new_window(pContainer.mlx, pContainer.map.cols * pContainer.sprite_h,
			pContainer.map.rows * pContainer.sprite_w , "so_long");	
		if (!pContainer.window)
			return 0;
		render_elements(&pContainer);
		render_player(&pContainer);
		insert_image(&pContainer);
		check_map_validity(&pContainer);
		mlx_loop_hook(pContainer.mlx, &insert_image, &pContainer);
		// mlx_hook(pContainer.window, 2, 1L<<0, &key_hook, &pContainer);
		mlx_loop(pContainer.mlx);
	}
}
