/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:17:53 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/21 21:17:54 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_container *pMap, char **map_visited,
		t_axis seeker, t_axis to_find)
{
	if (seeker.x < 0 || seeker.y < 0
		|| seeker.x >= pMap->map.cols
		|| seeker.y >= pMap->map.rows
		|| pMap->map.map[seeker.y][seeker.x] == WALL
		|| map_visited[seeker.y][seeker.x] == 'O')
		return (0);
	if (seeker.x == to_find.x && seeker.y == to_find.y)
		return (1);
	map_visited[seeker.y][seeker.x] = 'O';
	if (flood_fill(pMap, map_visited,
			(t_axis){seeker.x - 1, seeker.y}, to_find)
		|| flood_fill(pMap, map_visited,
			(t_axis){seeker.x, seeker.y + 1}, to_find)
		|| flood_fill(pMap, map_visited,
			(t_axis){seeker.x + 1, seeker.y}, to_find)
		|| flood_fill(pMap, map_visited,
			(t_axis){seeker.x, seeker.y - 1}, to_find))
		return (1);
	return (0);
}

int	check_elements_loop(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!check_element(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_array_reachability(t_container *pContainer, char **map_copy)
{
	int		i;

	i = -1;
	while (++i < pContainer->map.collectibles_count)
	{
		if (!flood_fill(pContainer, map_copy, pContainer->map.player_pos,
				pContainer->map.collectible_pos[i]))
		{
			ft_printf("Collectible not reachable\n");
			return (0);
		}
		reset_matrix_to_x(map_copy, pContainer->map.rows, pContainer->map.cols);
	}
	i = -1;
	while (++i < pContainer->map.enemies_count)
	{
		if (!flood_fill(pContainer, map_copy, pContainer->map.player_pos,
				pContainer->map.enemy_pos[i]))
		{
			ft_printf("Enemy not reachable\n");
			return (0);
		}
		reset_matrix_to_x(map_copy, pContainer->map.rows, pContainer->map.cols);
	}
	return (1);
}

int	check_if_reachable(t_container *pContainer)
{
	char	**map_copy;
	int		i;

	map_copy = copy_mtx(pContainer->map.map);
	reset_matrix_to_x(map_copy, pContainer->map.rows, pContainer->map.cols);
	if (!flood_fill(pContainer, map_copy, pContainer->map.player_pos,
			pContainer->map.exit_pos))
	{
		ft_printf("Exit not reachable\n");
		free_mtx(map_copy);
		return (0);
	}
	reset_matrix_to_x(map_copy, pContainer->map.rows, pContainer->map.cols);
	if (!check_array_reachability(pContainer, map_copy))
	{
		free_mtx(map_copy);
		return (0);
	}
	i = 0;
	while(map_copy && i < pContainer->map.rows)
	{
		free(map_copy[i]);
		map_copy[i] = NULL;
		i++;
	}
	free(map_copy);
	return (1);
}

int	check_map_validity(t_container *pContainer)
{
	if (!valid_cols(pContainer->map.map) || !valid_rows(pContainer->map.map)
		|| !check_rectangle(pContainer->map.map,
			pContainer->map.rows, pContainer->map.cols))
	{
		print_error(-1);
		return (0);
	}
	if (!check_elements_loop(pContainer->map.map)
		|| !check_elem_number(pContainer->map.map))
	{
		print_error(-2);
		return (0);
	}
	if (!check_if_reachable(pContainer))
	{
		print_error(-3);
		return (0);
	}
	return (1);
}

/* int main(void)
{
	t_container	pContainer;
	char	*tmp;
	int		i;

	char *path = "./maps/map.ber";
	i = 0;
	tmp = get_line(path);
	if (!check_nl(tmp))
	{
		free(tmp);
		ft_printf(-7);
		return 0;
	}
	pContainer.map.map = ft_split(tmp, '\n');
	i = 0;
	while(pContainer.map.map[i] != NULL)
		i++;
	
	pContainer.map.player_pos.x = 4;
	pContainer.map.player_pos.y = 1;
	pContainer.map.exit_pos.x = 1;
	pContainer.map.exit_pos.y = 1;
	pContainer.map.rows = 6;
	pContainer.map.cols = 24;
	char **map_visited = (char **)malloc(sizeof(char *) * 6);
	i = 0;
	while(i < 6)
	{
		map_visited[i] = (char *)malloc(sizeof(char) * 24);
		i++;
	}
	i = 0;
	while(i <6)
	{
		int j = 0;
		while(j < 24)
		{
			map_visited[i][j] = '0';
			j++;
		}
		i++;
	}
	i = flood_fill(&pContainer, map_visited,
		pContainer.map.player_pos, pContainer.map.exit_pos);
	printf("RISULTATO FINALE PRE CANNA%i\n", i);

}*/