#include "so_long.h"
#include <stdio.h>

/* static int	flood_fill2(t_container *pMap, char **map_visited, t_axis seeker, t_axis to_find)
{
	for(int i = 0; i < pMap->map.rows; i++)
	{
		for(int j = 0; j < pMap->map.cols; j++)
		{
			write(1, &map_visited[i][j], 1);
		}
		write(1, "\n", 1);
	}
	if (seeker.x < 0 || seeker.y < 0 || seeker.x >= pMap->map.rows || seeker.y >= pMap->map.cols ||
			pMap->map.map[seeker.x][seeker.y] == WALL || map_visited[seeker.x][seeker.y] == '*')
		return (0);
	if (seeker.x ==  to_find.x && seeker.y == to_find.y)
		return 1;
	map_visited[seeker.x][seeker.y] = '*';
	if (flood_fill2(pMap, map_visited, (t_axis){seeker.x - 1, seeker.y}, to_find) ||
			flood_fill2(pMap, map_visited, (t_axis){seeker.x, seeker.y + 1}, to_find) ||
			flood_fill2(pMap, map_visited, (t_axis){seeker.x + 1, seeker.y}, to_find) ||
			flood_fill2(pMap, map_visited, (t_axis){seeker.x, seeker.y - 1}, to_find))
			    return 1;
		return (0);
}  */
/*
	for(int i = 0; i < pMap->map.rows; i++)
	{
		for(int j = 0; j < pMap->map.cols; j++)
		{
			write(1, &map_visited[i][j], 1);
		}
		write(1, "\n", 1);
	}

void ft_print_structs(t_container *pContainer)
{
	int i;

	i = 0;
	ft_printf("map rows : %i\n", pContainer->map.rows);
	ft_printf("map cols: %i\n", pContainer->map.cols);
	ft_printf("map moves: %i\n", pContainer->map.moves);
	ft_printf("map collectibles: %i\n", pContainer->map.collectibles);
	ft_printf("map exit: %i\n", pContainer->map.exit);
	ft_printf("map enemies: %i\n", pContainer->map.enemies);
	ft_printf("map player.x: %i\n", pContainer->map.player_pos.x);
	ft_printf("map player.y: %i\n", pContainer->map.player_pos.y);
	ft_printf("exit pos.x: %i\n", pContainer->map.exit_pos.x);
	ft_printf("exit pos.y: %i\n", pContainer->map.exit_pos.y);
	while(i < pContainer->map.collectibles_count)
	{
		ft_printf("collectible pos.x: %i\n", pContainer->map.collectible_pos[i].x);
		ft_printf("collectible pos.y: %i\n", pContainer->map.collectible_pos[i].y);
		i++;
	}
	i = 0;
	while(i < pContainer->map.enemies_count)
	{
		ft_printf("enemy pos.x: %i\n", pContainer->map.enemy_pos[i].x);
		ft_printf("enemy pos.y: %i\n", pContainer->map.enemy_pos[i].y);
		i++;
	}
}

*/
/* int main(void)
{
	t_container	pContainer;
	char	*tmp;
	int		i;

	char *path = "./maps/map_noexit.ber";
	i = 0;
	tmp = get_line(path);
	if (!check_nl(tmp))
	{
		free(tmp);
		print_error(-7);
		return 0;
	}
	pContainer.map.map = ft_split(tmp, '\n');
	pContainer.map.player_pos = player_position(pContainer.map.map);
	pContainer.map.exit_pos = exit_potision(pContainer.map.map);
	pContainer.map.rows = count_rows(pContainer.map.map);
	pContainer.map.cols = count_cols(pContainer.map.map);
	char **map_visited = ft_calloc(pContainer.map.rows, sizeof(char *));
	i = 0;
	while(i < pContainer.map.rows)
	{
		map_visited[i] = ft_calloc(pContainer.map.cols, sizeof(char));
		i++;
    }
	i = 0;
	while(i < pContainer.map.rows)
	{
		int j = 0;
		while(j < pContainer.map.cols)
		{
			map_visited[i][j] = 'X';
			j++;
		}
		i++;
	}
	i = flood_fill2(&pContainer, map_visited, pContainer.map.player_pos, pContainer.map.exit_pos);
	printf("RISULTATO FINALE PRE CANNA: [%i]\n", i);

} */