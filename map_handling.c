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

/* int	dfs(t_map *map, int element_visited[map->rows][map->cols], t_axis *seeker, t_axis to_find)
{
	if (seeker->x < 0 || seeker->y < 0 || seeker->x >= map->rows
		|| seeker->y >= map->cols || element_visited[map->rows][map->cols] || map->map[map->rows][map->cols] == WALL)
		return (0);
	if 
} */

// int	dfs(t_map *map, int element_visited[map->rows][map->cols], t_axis *seeker, t_axis to_find)
// {
// /* 	if (rows < 0 || cols < 0 || rows >= map->rows || cols >= map->cols
// 			|| map->map[rows][cols] == WALL || element_visited[rows][cols])
// 		return (0); */
// /* 	if (map->map[rows][cols] == EXIT)
// 		return (1);
// 	element_visited[rows][cols] = 1; */
// 	if (seeker->x < 0 || seeker->y < 0 || seeker->x >= map->rows
// 		|| seeker->y >= map->cols || element_visited[map->rows][map->cols] || map->map[map->rows][map->cols] == WALL)
// 		return (0);
// 	if (dfs(map, element_visited, seeker + i, ) || dfs(map, rows + 1, cols, element_visited) || dfs(map, rows, cols - 1, element_visited)
// 			|| dfs(map, rows, cols + 1, element_visited))
// 		return (1);
// 	return (0);
// }

/* 	to_find.y--
	dfs(map, element_visited, to_find) 
	to_find.y+=2;
	dfs(map, rows + 1, cols, element_visited)
	
	dfs(map, rows, cols - 1, element_visited)
	dfs(map, rows, cols + 1, element_visited)) */

// int	is_valid_path(t_map *map)
// {
// 	int visited[map->rows][map->cols];
// 	memset(visited, 0, sizeof(visited));

// 	while(/*i < seeker_len**/)
// 	if (dfs(map, map->player_pos.x, map->player_pos.y, visited))
// 		return (1);
// 	else
// 		return (0);
// }
/* 
int	main(void)
{
	t_map	*map;
	int fd = open("./maps/map_2players.ber", O_RDONLY);
	char *line;
	char *tmp;
	char *res;
	// t_axis exit_pos = {1, 1};

	map = (t_map *)malloc(sizeof(t_map *) * 1);
	tmp = NULL;
	res = NULL;
	while (1)
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
	map->map = ft_split(tmp, '\n');
	map->rows = ft_strlen(map->map[0]);
	map->cols = ft_strlen(&map->map[0][0]);
	map->player_pos.x = 4;
	map->player_pos.y = 1;
	int i = is_valid_path(map);
	printf("Map is valid\n%i\n", i);
}
 */