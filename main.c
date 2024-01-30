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

/*  void ft_print_structs(t_container	*vars)
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
*/

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
		mlx_loop_hook(pContainer.mlx, &insert_images, &pContainer);
		mlx_loop(pContainer.mlx);
	}
}

/* 	controllare la coerenza delle variabili x & y su tutti i file e assicurarsi che siano messi tutti in linea
	bisogna implemtare :
		movimenti
		aggiornamento mappa in seguito all input del giocatore 
		tenere conto del numero delle mosse t_map->moves
		chiusura del gioco
		inseguimeto dei nemici
		animazione del player
 */
		// mlx_hook(pContainer.window, 2, 1L<<0, &key_hook, &pContainer);

/* typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("%d", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
} */

