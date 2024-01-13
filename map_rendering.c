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

char	*read_map(t_map *map_ptr, char *path)
{
	int		fd;
	char	*buffer;
	int		i;

	buffer = ft_calloc();
	if (!buffer)
		return (NULL);
	fd = open(path, O_RDONLY);
	i = 0;

}

char	*ft_read_map(t_container *map, char *path)
{
	int		fd;
	char	*line;
	char	*read;

	read = ft_calloc(1, 1);
	if (!read)
		return (NULL);
	fd = open(path, O_RDONLY);
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
