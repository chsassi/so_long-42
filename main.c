#include "so_long.h"

void	init_vars(t_container *container_ptr) // passare anche altre struct da allocare
{
	container_ptr->window_w = 0;
	container_ptr->window_h = 0;
	container_ptr->floor = NULL;
	container_ptr->wall = NULL;
	container_ptr->exit = NULL;
	container_ptr->player[0] = NULL;
	container_ptr->player[1] = NULL;
	container_ptr->player[2] = NULL;
	container_ptr->player[3] = NULL;
	container_ptr->enemy = NULL;
	container_ptr->collectible = NULL;
	container_ptr->sprite_w = 1;
	container_ptr->sprite_h = 1;
	container_ptr->map->collectibles = 0;
	container_ptr->map->moves = 0;
	container_ptr->map->exit = 0;
	container_ptr->map->player_pos.x = 0;
	container_ptr->map->player_pos.y = 0;
}

void	init_window(t_container *init)
{
	init->game = mlx_init();
	init->game = mlx_new_window(init->game, (32 * init->sprite_w),
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
	if (check_args(ac, path) == 1)
	{
		render_map(container_ptr->map, path);
		init_window(container_ptr);
	}
}
