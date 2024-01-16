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

# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
# include "./Libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/gnl.h"
# include <X11/Xlib.h>
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

# define SPRITE_WIDTH 32
# define SPRITE_HEIGHT 32

typedef struct s_axis
{
	int	x;
	int	y;
}	t_axis;

typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	int			collectibles;
	int			moves;
	int			exit;
	t_axis		player_pos;
}	t_map;

typedef struct s_container
{
	void	*game;
	void	*window;
	void	*player[4];
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*enemy;
	int		window_w;
	int		window_h;
	int		sprite_w;
	int		sprite_h;
	t_map	*map;
}	t_container;

typedef struct s_ultimate
{
	t_container	*window_data;
}	t_ultimate;

/* Map Rendering */

char	*render_map(t_map *map_ptr, char *ptr);

/* Utils */

size_t	strlen_sl(char *s);
void	print_error(char *error_msg, char **mtx);
int		element_check(char c);

/* Image Rendering */

void	render_player(t_container *img);
void	render_elements(t_container *img);
void	insert_image(t_container *img, int x, int y);

/* Process Endgame */

void	free_map(char **map);
void	free_images(t_container *free);
int		quit_game(t_container *quit);

/* Main */

void	init_vars(t_container *init);
void	init_window(t_container *init);

#endif