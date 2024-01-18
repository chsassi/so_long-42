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

int		check_nl(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (0);
		else
			return (1);
	}
}

int	*check_map(t_map *ptr, char *path, int fd)
{
	char	*tmp;
	char	*tmp2;
	char	*res;

	while (42)
	{
		tmp = gnl(fd);
		if(tmp == NULL)
		{
			free(tmp);
			break ;
		}
		res = tmp2;
		tmp2 = strjoin_gnl(res, tmp);
	}
	if (check_nl(tmp2) == 1)
	{
		ptr->map = ft_split(tmp2, '\n');
		return (1);
	}
	else
		return (0);
}

char	*render_map(t_map *ptr, char *path)
{
	int		fd;
	char	*tmp;
	char* 	res;
	char* 	tmp2;
	char** mtx;
	int		i;

	i = 0;
	path = ft_strjoin("./maps/", path);
	res = NULL;
	tmp2 = NULL;
	fd = open(path, O_RDONLY);

	/* TODO abbiamo allocato la mappa, ora bisogna controllare che i valori della mappa siano corretti
	 * bisogna fare una funzione che faccia il parsing della mappa:
	 *	- controllare che sia valida (int element_check(char c), NO '\n', .... )
	 *  -controlli che siano presenti una uscita e un giocatore
	 * 	-controlli che sia presente almeno un percorso valido
	*/
	while (tmp)
		ptr->map[i++] = ft_strtrim(tmp, "\n");
	free(tmp);
	return (*ptr->map);
}
