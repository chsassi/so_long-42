/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:52:27 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/11 18:52:28 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_image(t_container *img, int x, int y)
{
	if (img->map.map[x][y] == '1')
		mlx_put_image_to_window(img->game, img->window, img->wall, img->sprite_w, img->sprite_h);
	else if (img->map.map[x][y] == '0')
		mlx_put_image_to_window(img->game, img->window, img->floor, img->sprite_w, img->sprite_h);
	else if (img->map.map[x][y] == 'C')
		mlx_put_image_to_window(img->game, img->window, img->collectible, img->sprite_w, img->sprite_h);
	else if (img->map.map[x][y] == 'E')
		mlx_put_image_to_window(img->game, img->window, img->exit, img->sprite_w, img->sprite_h);
	else if (img->map.map[x][y] == 'P')
		mlx_put_image_to_window(img->game, img->window, img->exit, img->sprite_w, img->sprite_h);
}

int	check_borders(t_map *map)
{
	int valid = 1;
	int exit_found = 0;
	int collectible_found = 0;

	if (map->rows <= 0 || map->cols <= 0)
	{
		print_error("Invalid map dimensions", NULL);
		return (0);
	}
}

char	*ft_read_map(char *map)
{
	int		fd;
	char	*line;
	char	*read;

	read = ft_calloc(1, 1);
	if (!read)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd >= 0 || fd <= 1024)
	{
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			read = ft_strjoin(read, line);
			free(line);
		}
		close(fd);
	}
	return (read);
}
