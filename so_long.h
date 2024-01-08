/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:48:19 by chsassi           #+#    #+#             */
/*   Updated: 2024/01/08 18:48:22 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_ESC 65307

typedef struct s_axis
{
	int	x;
	int	y;
}	t_axis;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*player_exit;
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*enemy;
	int		window_w;
	int		window_h;
	int		sprite_w;
	int		sprite_h;
}	t_window;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		collectibles;
	int		moves;
	t_axis	player_pos;
}	t_map;

#endif