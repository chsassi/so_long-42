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
	char* 	res;
	char* 	tmp2;
	char** mtx;
	int		i;

	i = 0;
	path = ft_strjoin("./maps/", path);
	res = NULL;
	tmp2 = NULL;
	fd = open(path, O_RDONLY);
	while(42)
	{
		tmp = gnl(fd);
		if(tmp == NULL)
		{
			/**vanno fatti i free*/
			break ;
		}
		res = tmp2;
		tmp2 = strjoin_gnl(res, tmp);
	}
	ptr->map = ft_split(tmp2, '\n');
	/* TODO abbiamo allocato la mappa, ora bisogna controllare che i valori della mappa siano corretti
	 * bisogna fare una funzione che faccia il parsing della mappa:
	 * 	-controlli che i bordi siano tutti 1
	 *	- controllare che sia valida (int	element_check(char c), NO '\n', .... )
	 *  -controlli che siano presenti una uscita e un giocatore
	 * 	-controlli che sia presente almeno un percorso valido
	*/
	while (tmp)
		ptr->map[i++] = ft_strtrim(tmp, "\n");
	free(tmp);
	return (*ptr->map);
}
