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
