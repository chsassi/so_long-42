#include "so_long.h"

void	init_vars(t_container *init)
{
	init->window_w = 1;
	init->window_h = 1;
	init->floor = NULL;
	init->wall = NULL;
	init->exit = NULL;
	init->player[0] = NULL;
	init->player[1] = NULL;
	init->player[2] = NULL;
	init->player[3] = NULL;
	init->enemy = NULL;
	init->collectible = NULL;
	init->sprite_w = 0;
	init->sprite_h = 0;
	init->map = 0;
	init->map->rows = 0;
	init->map->cols = 0;
	init->map->collectibles = 0;
	init->map->moves = 0;
	init->map->exit = 0;
	init->map->player_pos.x = 0;
	init->map->player_pos.y = 0;
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
	t_container	*container_ptr;

	path = av[1];
	container_ptr = ft_calloc(sizeof(t_container), 1);
	container_ptr->map = ft_calloc(sizeof(t_map), 1);
	init_vars(container_ptr);
	if (ac == 2)
	{
		render_map(container_ptr->map, path);
		init_window(container_ptr);
	}
	if (ac > 2)
		ft_printf("Too many arguments. Run with './so_long' and a .ber file");
	else
		ft_printf("Too few arguments. Run with './so_long' and a .ber file");
	return (0);
}
