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
# include <stddef.h>
# include <strings.h>
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

# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define ENEMY 'N'
# define EXIT 'E'
# define FLOOR '0'
# define WALL '1'

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
	int			moves;
	int			exit;
	int			collectibles;
	int			collectibles_count;
	int			enemies;
	int			enemies_count;
	t_axis		player_pos;
	t_axis		exit_pos;
	t_axis		*collectible_pos;
	t_axis		*enemy_pos;
}	t_map;

typedef struct s_container
{
	void	*mlx;
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
	t_map	map;
}	t_container;

/* Image Rendering */
void	render_player_image(t_container *pContainer);
void	render_element_image(t_container *pContainer);
void	render_sprite_on_mtx(t_container *pContainer, int rows, int cols);
int		render_sprite_loop(t_container *pContainer);
int		insert_images(t_container *pContainer);

/* Parsing */
int		check_nl(char *s);
char	*get_line(char *path);
char	**get_mtx(char *path);

/* Map Checks*/
int		check_mtx_rows(char *mtx);
int		valid_rows(char **mtx);
int		check_mtx_cols(char **mtx);
int		valid_cols(char **mtx);
int		check_rectangle(char **map, int rows, int cols);

/* Map Handling */
int		flood_fill(t_container *pMap, char **map_visited, t_axis seeker, t_axis to_find);
int		check_elem_number(char **map);
int		check_elements_loop(char **map);
int		check_if_reachable(t_container *pContainer);
int		check_map_validity(t_container *pContainer);

/* Position */
t_axis	player_position(char **mtx);
t_axis	exit_potision(char **mtx);
t_axis	*collectibles_position(char **mtx, t_container *pContainer);
t_axis	*enemies_position(char **mtx, t_container *pContainer);
void	init_element_position(char **mtx, t_container *pContainer);

/* Endgame */
void	free_map(char **map);
void	free_images(t_container *pContainer);
int		quit_game(t_container *pContainer);

/* Init */
void	init_map(t_map *pMap);
void	init_container(t_container *pContainer);
void init_all_innit(t_container *pContainer, char* path);
/* Utils */
int		check_element(char c);
int		count_elements(char **mtx, char c);
int		check_args(int ac, char *map_file);
int		count_cols(char **mtx);
int		count_rows(char **mtx);
int		print_error(int error_nbr);

// 2 players
// 0 players
// spazio
// rettangolo
// 0 tra 1

#endif