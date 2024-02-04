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


void ft_print_structs(t_container	*vars)
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
}


int	execute(t_container *pContainer, int keycode)
{
/* 	char	**map_copy;
 */
	if (keycode == KEY_ESC)
	{
		printf("%i", keycode);
		exit (0);
	}
	else if(keycode == KEY_A)
	{
		printf("%i", keycode);
		pContainer->map.map[pContainer->map.player_pos.x - 1][pContainer->map.player_pos.y] = PLAYER;
		pContainer->map.map[pContainer->map.player_pos.x][pContainer->map.player_pos.y] = FLOOR;
	}
	insert_images(pContainer);

/* 	map_copy = copy_mtx(pContainer->map.map);
	update_player_pos(pContainer, map_copy, keycode);
	update_coll_pos(pContainer, map_copy, keycode);
	update_enemy_pos();
	check_map_copy();
	update_original_map(pContainer);
	*/
	return (1);
	}

int	main(int ac, char** av)
{
	t_container	pContainer;
	char		*path;

	path = ft_strjoin("maps/", av[1]);
	if (check_args(ac, path))
	{
		init_all_innit(&pContainer, path);
		if(!check_map_validity(&pContainer))
			return 0;
		insert_images(&pContainer);
		mlx_hook(pContainer.window, 2, 1L << 0, &execute, &pContainer);
		mlx_loop_hook(pContainer.mlx, &execute, &pContainer);
/* 		mlx_key_hook(pContainer.window, &execute, &pContainer);
 */		mlx_loop(pContainer.mlx);
	}
}

	/* pContainer->map.map[player_x][player_y] =  */

/* 		una volta che ho la nuova posizione del player 
		posso controllare se si sovrappone alla posizione di un collezionabile
		se si : ->coll_count - 1 / collectibles++ / coll_pos (remove pos coll) / change [C]->[0]
		
		se il num di coll di map_copy -1 rispetto a orinal map->richiamo count_coll & coll_pos 

		controllare libreria per il movimento dei nemici
		una volta che ho la nuova posizione del player 
		posso controllare se si sovrappone alla posizione di un collezionabile
		se si : ->coll_count - 1 / collectibles++ / coll_pos (remove pos coll) / change [C]->[0]

		qui dopo aver mosso tutti i muovibili, rifacciamo i controlli sulla raggiungibilita
 */