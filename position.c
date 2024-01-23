#include "so_long.h"

t_axis	player_position(char **mtx)
{
	t_axis	player_pos;
	int		rows;
	int		cols;

	rows = 0;
	cols = 0;
	while(mtx[rows] != NULL)
	{
		cols = 0;
		while(mtx[rows][cols] != '\0')
		{
			if(mtx[rows][cols] == 'P')
			{
				player_pos.x = rows;
				player_pos.y = cols;
			}
			cols++;
		}
		rows++;
	}
	return (player_pos);
}

t_axis	exit_potision(char **mtx)
{
	t_axis	exit_pos;
	int		rows;
	int		cols;

	rows = 0;
	cols = 0;
	while(mtx[rows] != NULL)
	{
		cols = 0;
		while(mtx[rows][cols] != '\0')
		{
			if(mtx[rows][cols] == EXIT)
			{
				exit_pos.x = cols;
				exit_pos.y = rows;
			}
			cols++;
		}
		rows++;
	}
	return (exit_pos);
}

t_axis	*collectibles_position(char **mtx, t_container *vars)
{
	t_axis	*collectibles_pos;
	int		rows;
	int		cols;
	int		collectible_nbr;
	int		i;

	rows = -1;
	i = 0;
	collectible_nbr = count_elements(mtx, COLLECTIBLE);
	vars->map.collectibles_count = collectible_nbr;
	collectibles_pos = ft_calloc(collectible_nbr, sizeof(t_axis));
	while (collectible_nbr != 0 && mtx[++rows] != NULL)
	{
		cols = -1;
		while (mtx[rows][++cols] != '\0')
		{
			if (mtx[rows][cols] == COLLECTIBLE)
			{
				collectibles_pos[i].x = cols;
				collectibles_pos[i].y = rows;
				collectible_nbr--;
				i++;
			}
		}
	}
	return (collectibles_pos);
}

t_axis	*enemies_position(char **mtx, t_container *vars)
{
	t_axis	*enemy_pos;
	int		rows;
	int		cols;
	int		enemy_nbr;
	int		i;

	rows = -1;
	i = 0;
	enemy_nbr = count_elements(mtx, ENEMY);
	vars->map.enemies_count = enemy_nbr;
	enemy_pos = ft_calloc(enemy_nbr, sizeof(t_axis));
	while (enemy_nbr != 0 && mtx[++rows] != NULL)
	{
		cols = -1;
		while (mtx[rows][++cols] != '\0')
		{
			if (mtx[rows][cols] == ENEMY)
			{
				enemy_pos[i].x = cols;
				enemy_pos[i].y = rows;
				enemy_nbr--;
				i++;
			}
		}
	}
	return (enemy_pos);
}
