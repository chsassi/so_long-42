/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:52:27 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/11 18:52:28 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_nl(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (0);
	}
	return (1);
}

char	*get_line(char *path)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*res;

	fd = open(path, O_RDONLY);
	while (42)
	{
		line = gnl(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		res = tmp;
		tmp = strjoin_gnl(&res, line);
	}
	close(fd);
	return (tmp);
}

char	**get_mtx(t_map *ptr, char *path)
{
	int		i;
	char	*tmp;
	int		lines_read;

	i = 0;
	tmp = get_line(path);

	if (!check_nl(tmp))
	{
		free(tmp);
		ft_printf("Map contains invalid lines.");
		return (0);
	}
	ptr->map = ft_split(tmp, "\n");
}
	free(ptr->map);
	return (ptr->map);
}
