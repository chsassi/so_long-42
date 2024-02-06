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

# include "mlx.h"
# include "mlx_int.h"
# include <libft.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

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
# define EXTRA_WIN 20

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
	int			collectibles_count;
	int			enemies_count;
	int			player_direction;
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

/* Endgame */
void	free_images(t_container *pContainer);
int		quit_game(t_container *pContainer);
int		close_window(int keycode, t_container *pContainer);

/* Image Rendering */
void	render_player_image(t_container *pContainer);
void	render_element_image(t_container *pContainer);
void	render_sprite_on_mtx(t_container *pContainer, int rows, int cols);
int		render_sprite_loop(t_container *pContainer);
int		insert_images(t_container *pContainer);

/* Init Game */
int		check_args(int ac, char *map_file);
void	init_map(t_map *pMap);
void	init_container(t_container *pContainer);
void	init_element_position(char **mtx, t_container *pContainer);
void	init_all_innit(t_container *pContainer, char *path);

/* Map Checks */
int		check_mtx_rows(char *mtx);
int		valid_rows(char **mtx);
int		check_mtx_cols(char **mtx);
int		valid_cols(char **mtx);
int		check_rectangle(char **map, int rows, int cols);

/* Map Parsing */
int		check_nl(char *s);
char	*get_line(char *path);
char	**get_mtx(char *path);

/* Map Handling */
int		flood_fill(t_container *pMap, char **map_visited,
			t_axis seeker, t_axis to_find);
int		check_array_reachability(t_container *pContainer, char **map_copy);
int		check_reachability(t_container *pContainer);
int		check_map_validity(t_container *pContainer);

/* Position */
t_axis	player_position(char **mtx);
t_axis	exit_potision(char **mtx);
t_axis	*collectibles_position(char **mtx, t_container *pContainer);
t_axis	*enemies_position(char **mtx, t_container *pContainer);

/* Movement Handling */
void	handle_movement(int keycode, t_container *pContainer);
void	handle_enemies(t_container *pContainer);
void	handle_collectibles(t_container *pCont);
void	handle_win(t_container *pCont);
void	handle_death(t_container *pCont);

/* Movement Checks*/
int		is_walkable(int keycode, t_container *pContainer);
void	move_up(int keycode, t_container *pContainer);
void	move_right(int keycode, t_container *pContainer);
void	move_down(int keycode, t_container *pContainer);
void	move_left(int keycode, t_container *pContainer);

/* Utils */
int		check_element(char c);
int		check_elem_number(char **map);
int		print_error(int error_nbr);
void	print_stats(t_container *pContainer);
void	print_game_start();

#endif