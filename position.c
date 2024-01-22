#include "so_long.h"

t_axis	player_position(char **mtx, t_container *vars)
{
	t_axis	player_pos;
	int		rows;
	int		cols;

	rows = 0;
	cols = 0;
	while(mtx[rows] != NULL)
	{
		while(mtx[rows][cols] != NULL)
		{
			if(mtx[rows][cols] == PLAYER)
			{
				player_pos.x = cols;
				player_pos.y = rows;
			}
			cols++;
		}
		rows++;
	}
	return (player_pos);
}

t_axis	exit_potision(char **mtx, t_container *vars)
{
	t_axis	exit_pos;
	int		rows;
	int		cols;

	rows = 0;
	cols = 0;
	while(mtx[rows] != NULL)
	{
		while(mtx[rows][cols] != NULL)
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
	t_axis	*exit_pos;
	int		rows;
	int		cols;
	int		collectible_nbr;

	rows = 0;
	cols = 0;
	collectible_nbr = 0;
	while(mtx[rows] != NULL)
	{
		while(mtx[rows][cols] != NULL)
		{
			if (mtx[rows][cols] == COLLECTIBLE)
				collectible_nbr++;
			cols++;
		}
		rows++;
	}
	exit_pos = ft_calloc(collectible_nbr, sizeof(t_axis));
	while (collectible_nbr > 0 && mtx[rows] != NULL)
	{
		while (mtx[rows][cols] != NULL)
		{
			if (mtx[rows][cols] == COLLECTIBLE)
			{
				vars->map
				collectible_nbr--;
			}
		}
	}
	return ();
}

t_axis	enemies_position(char **mtx, t_container *vars)
{
	t_axis	exit_pos;
	int		rows;
	int		cols;
	int		enemy_nbr;

	rows = 0;
	cols = 0;
	enemy_nbr = vars->map.collectibles;
	while(mtx[rows] != NULL)
	{
		while(mtx[rows][cols] != NULL)
		{
			if (mtx[rows][cols] == ENEMY)
				enemy_nbr++;
			cols++;
		}
		rows++;
	}
	return ();
}
