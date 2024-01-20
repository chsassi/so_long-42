#include "so_long.h"

int	check_element(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C' || c == 'N')
		return (1);
	else
	{
		ft_printf("Map is invalid.");
		return (0);
	}
}

int	check_borders(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
		{
			ft_printf("Map is invalid.");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(char *s)
{
	size_t	len;

	len = strlen_sl(s);
	if (s[0] == '1' && (s[len] - 1) == '1')
		return (1);
	else
		return (0);
}

int	check_rectangle(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (strlen_sl(map[i]) != cols)
		{
			ft_printf("Map is not rectangular.");
			return (0);
		}
		i++;
	}
	return (1);
}

int dfs(t_map *map, int x, int y, int visited[map->rows][map->cols]) {
    // Check if the current position is out of bounds, a wall, or already visited
    if (x < 0 || y < 0 || x >= map->rows || y >= map->cols || map->map[x][y] == '1' || visited[x][y]) {
        return 0;
    }

    // Check if the current position is the exit
    if (map->map[x][y] == 'E') {
        return 1;
    }

    // Mark the current position as visited
    visited[x][y] = 1;

    // Call the DFS function for each of the four directions
    if (dfs(map, x - 1, y, visited) || dfs(map, x + 1, y, visited) || dfs(map, x, y - 1, visited) || dfs(map, x, y + 1, visited)) {
        return 1;
    }

    return 0;
}

int is_valid_path(t_map *map) {
    int visited[map->rows][map->cols];
    memset(visited, 0, sizeof(visited));

    if (dfs(map, map->player_pos.x, map->player_pos.y, visited)) {
        return 1;
    } else {
        return 0;
    }
}