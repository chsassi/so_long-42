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

/* static int	check_borders(t_map *map)
{
	int valid = 1;
	int exit_found = 0;
	int collectible_found = 0;

	if (map->rows <= 0 || map->cols <= 0)
	{
		print_error("Invalid map dimensions", NULL);
		return (0);
	}
} */

char	*render_map(t_map *ptr, char *path)
{
	int		fd;
	char	*tmp;
	int		i;

	fd = open(path, O_RDONLY);
	tmp = gnl(fd);
	i = 0;
	ptr->map = ft_calloc(sizeof(char *), 2);
	if (!ptr->map)
		return (NULL);
	while (tmp)
		ptr->map[i++] = ft_strtrim(tmp, "\n");
	free(tmp);
	return (*ptr->map);
}
