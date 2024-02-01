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
	while (s && s[i] && s[i + 1])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_line(char *path)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*res;

	res = NULL;
	tmp = NULL;
	fd = open(path, O_RDONLY);
	while (42)
	{
		line = gnl(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		tmp = strjoin_gnl(&res, line);
		res = tmp;
	}
	close(fd);
	return (tmp);
}

char	**get_mtx(char *path)
{
	char	*tmp;
	char	**res;

	tmp = get_line(path);
	if (!check_nl(tmp))
	{
		free(tmp);
		print_error(-7);
		return (0);
	}
	res = ft_split(tmp, '\n');
	free(tmp);
	return (res);
}
