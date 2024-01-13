#include "so_long.h"

void	init_vars(t_map *init)
{
	init->map = NULL;
	init->rows = 1;
	init->cols = 0;
	init->collectibles = 0;
	init->moves = 0;
	init->game.window_w = 1;
	init->game.window_h = 1;
	init->player_pos.x = 0;
	init->player_pos.y = 0;
	init->game.floor = NULL;
	init->game.wall = NULL;
	init->game.exit = NULL;
	init->game.player[0] = NULL;
	init->game.enemy = NULL;
	init->game.collectible = NULL;
}

void	init_window(t_container *init)
{
	init->game = mlx_init();
	init->window = mlx_new_window(init->window, (32 * init->sprite_w),
			(32 * init->sprite_h), "so_long");
}

int	main(int ac, char **av)
{
	char		*path;
	t_map		*map_ptr;
	t_container	*container_ptr;

	path = av[1];
	init_vars(&map_ptr);
	if (ac == 2)
	{
		//mappa
		init_window(&container_ptr);
	}
	if (ac > 2)
		ft_printf("Too many arguments. Run with './so_long' and a .ber file");
	else
		ft_printf("Too few arguments. Run with './so_long' and a .ber file");
	return (0);
}
