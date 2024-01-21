#include "so_long.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->moves = 0;
	map->exit = 0;
	map->rows = 0;
	map->cols = 0;
	map->collectibles = 0;
	map->player_pos.x = 0;
	map->player_pos.y = 0;

}
void	init_container(t_container *vars)
{
	vars->window_w = 0;
	vars->window_h = 0;
	vars->floor = NULL;
	vars->wall = NULL;
	vars->exit = NULL;
	vars->player[0] = NULL;
	vars->player[1] = NULL;
	vars->player[2] = NULL;
	vars->player[3] = NULL;
	vars->enemy = NULL;
	vars->collectible = NULL;
	vars->sprite_w = 1;
	vars->sprite_h = 1;
	vars->map.moves = 0;
	vars->map.exit = 0;
	}

void	init_window(t_container *init)
{
	init->game = mlx_init();
	init->game = mlx_new_window(init->game, (32 * init->sprite_w),
			(32 * init->sprite_h), "so_long");
}
void init_all_innit(t_container *var_container)
{
	init_container(var_container);
	init_map(&var_container->map);
}

int	main(int ac, char **av)
{
	char		*path;
	t_container	vars;

	init(&vars);
	if (check_args(ac, path) == 1)
	{
		path = av[1];
		render_map(vars->map, path);
		init_window(vars);
	}
}
