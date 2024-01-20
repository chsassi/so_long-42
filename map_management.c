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

int check_valid_map_path(char **map, int rows, int cols)
{
	int i, j;
	int player_found = 0;
	int exit_found = 0;
	int collectibles_count = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			char c = map[i][j];

			if (c == 'P')
			{
				if (player_found)
				{
					ft_printf("Map is invalid: Multiple players found.");
					return 0;
				}
				player_found = 1;
			}
			else if (c == 'E')
			{
				if (exit_found)
				{
					ft_printf("Map is invalid: Multiple exits found.");
					return 0;
				}
				exit_found = 1;
			}
			else if (c == 'C')
			{
				collectibles_count++;
			}
			else if (c == 'N')
			{
				ft_printf("Game over: Player hit a N.");
				return 0;
			}
			else if (c != '0' && c != '1')
			{
				ft_printf("Map is invalid: Invalid character found.");
				return 0;
			}
		}
	}

	if (!player_found)
	{
		ft_printf("Map is invalid: Player not found.");
		return 0;
	}

	if (collectibles_count == 0 && !exit_found)
	{
		ft_printf("Map is invalid: No exit found.");
		return 0;
	}

	return 1;
}
