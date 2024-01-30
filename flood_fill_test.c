#include "so_long.h"
#include <stdio.h>



static int	flood_fill2(t_container *pMap, char **map_visited, t_axis seeker, t_axis to_find)
{
    int i;

    i = 0;
    while(i < pMap->map.rows)
    {
        puts(map_visited[i++]);

    }
    printf("\n------------------\n");
	if (seeker.x < 0 || seeker.y < 0 || seeker.x >= pMap->map.cols || seeker.y >= pMap->map.rows ||
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
} 


int main(void)
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
		print_error(-7);
		return 0;
	}
	pContainer.map.map = ft_split(tmp, '\n');
	i = 0;
	while(pContainer.map.map[i] != NULL)
		i++;	
	pContainer.map.player_pos.x = 2;
	pContainer.map.player_pos.y = 5;
	pContainer.map.exit_pos.x = 2;
	pContainer.map.exit_pos.y = 7;
	pContainer.map.rows = 6;
	pContainer.map.cols = 25;
	char **map_visited = (char **)ft_calloc(pContainer.map.rows, sizeof(char *));
	i = 0;
	while(i < pContainer.map.rows)
	{
		map_visited[i] = (char *)ft_calloc(pContainer.map.cols, sizeof(char));
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

}