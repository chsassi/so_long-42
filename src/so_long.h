/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:48:19 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/10 15:56:34 by chsassi          ###   ########.fr       */
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

# define EXTRA_WIN 34
# define MAX_SCREEN_COLS 61
# define MAX_SCREEN_ROWS 30

# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define ENEMY 'N'
# define EXIT 'E'
# define FLOOR '0'
# define WALL '1'

typedef enum e_error
{
	INVALID_RENDER,
	INVALID_CHARS,
	INVALID_REACHABILITY,
	INVALID_ARGS,
	INVALID_ARGS2,
	INVALID_FORMAT,
	INVALID_PARSING,
	INVALID_SCREEN_SIZE,
}	t_error;

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
	int			seed_randomizer;
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
	void	*pixel_reset;
	int		window_w;
	int		window_h;
	int		sprite_w;
	int		sprite_h;
	int		pixel_reset_w;
	int		pixel_reset_h;
	t_map	map;
}	t_container;

/**
 * @brief Frees the memory allocated for the map.
 * This function is responsible for freeing the memory allocated for the map in the t_container structure.
 * @param pContainer A pointer to the t_container structure.
 * @return void
 */
void	free_map(t_container *pContainer);

/**
 * @brief Frees the memory allocated for the position in the t_container structure.
 * This function is responsible for freeing the memory allocated for the position in the t_container structure.
 * @param pContainer A pointer to the t_container structure.
 * @return void
 */
void	free_position(t_container *pContainer);

/**
 * @brief Frees the memory allocated for the images in the t_container structure.
 * This function is responsible for freeing the memory allocated for the images in the t_container structure.
 * @param pContainer A pointer to the t_container structure.
 * @return void
*/
void	free_images(t_container *pContainer);

/**
 * @brief Quits the game and frees everything.
 * This function is responsible for freeing the memory allocated for the t_container structure.
 * @param pContainer A pointer to the t_container structure.
 * @return An integer value indicating the status of the game.
 */
int		quit_game(t_container *pContainer);

/**
 * @brief Closes the window and frees the memory allocated for the t_container structure.
 * This function is responsible for closing the window and freeing the memory allocated for the t_container structure.
 * @param keycode The key code representing the user input.
 * @param pContainer A pointer to the t_container structure.
 * @return An integer value indicating the status of the game.
 */
int		close_window(int keycode, t_container *pContainer);

/**
 * @brief Gets a random seed within a specified range.
 * This function takes a pointer to a random number generator function and a range as parameters.
 * It returns an integer value representing the random seed within the specified range.
 * @param rand A pointer to the random number generator function.
 * @param range The range within which the random seed should be generated.
 * @return An integer value representing the random seed within the specified range.
*/
int		get_seed(int (*rand)(), int range);

/**
 * @brief Checks the surrounding tiles of an enemy.
 * This function checks the tiles around an enemy in a specified direction to determine if it is a valid move.
 * @param pContainer A pointer to the t_container structure.
 * @param enemy A pointer to the t_axis structure representing the enemy's position.
 * @param direction An integer value representing the direction to check (0: up, 1: down, 2: left, 3: right).
 * @return An integer value indicating if the move is valid (1) or not (0).
*/
int		check_around_enemy(t_container *pContainer,
			t_axis *enemy, int direction);

/**
 * @brief Moves the enemy in a specified direction.
 * This function moves the enemy in a specified direction based on the given parameters.
 * @param pContainer A pointer to the t_container structure.
 * @param enemy A pointer to the t_axis structure representing the enemy's position.
 * @param direction An integer value representing the direction to move (0: up, 1: down, 2: left, 3: right).
 * @return void
*/
void	enemy_moves(t_container *pContainer, t_axis *enemy);

/**
 * @brief Renders the player image on the window.
 * This function renders the player image on the window based on the given parameters.
 * @param pContainer A pointer to the t_container structure.
 * @return void
*/
void	render_player_image(t_container *pContainer);

/**
 * @brief Renders images on the window.
 * This function renders the images on the window based on the given parameters.
 * @param pContainer A pointer to the t_container structure.
 * @return void
*/
void	render_element_image(t_container *pContainer);

/**
 * @brief Renders the sprites on the matrix.
 * @param pContainer A pointer to the t_container structure.
 * @param rows The number of rows in the matrix.
 * @param cols The number of columns in the matrix.
 * @return void
*/
void	render_sprite_on_mtx(t_container *pContainer, int rows, int cols);

/**
 * @brief Renders the sprites on every loop.
 * @param pContainer A pointer to the t_container structure.
 * @return 1 if the rendering is successful, 0 otherwise.
*/
int		render_sprite_loop(t_container *pContainer);

/**
 * @brief Renders the sprites on the window.
 * @param pContainer A pointer to the t_container structure.
 * @return void
*/
int		insert_images(t_container *pContainer);

/**
 * @brief Initializes map elements.
 * @param pContainer A pointer to the t_container structure.
 * @return void
*/
void	init_map(t_map *pMap);

/**
 * @brief Initializes the window and the images.
 * @param pContainer A pointer to the t_container structure.
 * @return void
*/
void	init_container(t_container *pContainer);

/**
 * @brief Initializes elements position.
 * @param pContainer A pointer to the t_container structure.
 * @return void
*/
void	init_element_position(char **mtx, t_container *pContainer);

/**
 * @brief Initializes all the elements.
 * @param pContainer A pointer to the t_container structure.
 * @param path The path to the map file.
 * @return void
*/
void	init_all_innit(t_container *pContainer, char *path);

/**
 * @brief Checks the number of rows in a matrix.
 * This function takes a matrix as input and checks the number of rows in it.
 * @param mtx The matrix to check.
 * @return The number of rows in the matrix.
*/
int		check_mtx_rows(char *mtx);

/**
 * @brief Checks if the given mtx rows are valid.
 * @param map The matrix.
 * @return 1 if the rows are valid, 0 otherwise.
*/
int		valid_rows(char **mtx);

/**
 * @brief Checks the number of cols in a matrix.
 * This function takes a matrix as input and checks the number of cols in it.
 * @param mtx The matrix to check.
 * @return The number of cols in the matrix.
*/
int		check_mtx_cols(char **mtx);

/**
 * @brief Checks if the given mtx cols are valid.
 * @param map The matrix.
 * @return 1 if the cols are valid, 0 otherwise.
*/
int		valid_cols(char **mtx);

/**
 * @brief Checks if the given mtx is valid.
 * @param map The matrix.
 * @param rows rows.
 * @param cols cols.
 * @return 1 if the matrix is valid, 0 otherwise.
*/
int		check_rectangle(char **map, int rows, int cols);

/**
 * @brief Performs flood fill algorithm on a map to find a specific character.
 * This function recursively explores the map starting from a given position (seeker) and searches for a specific character (to_find).
 * It marks the visited positions on the map_visited array to avoid revisiting them.
 * 
 * @param pMap A pointer to the container structure that holds the map data.
 * @param map_visited A 2D array representing the visited positions on the map.
 * @param seeker The starting position for the flood fill algorithm.
 * @param to_find The character to search for in the map.
 * @return The number of positions visited during the flood fill algorithm.
 */
int		flood_fill(t_container *pMap, char **map_visited,
			t_axis seeker, t_axis to_find);

/**
 * @brief Checks the reachability of elements in an array.
 * 
 * This function takes a pointer to a container and a copy of a map as parameters.
 * It checks the reachability of elements in the array and returns an integer value.
 * 
 * @param pContainer A pointer to the container.
 * @param map_copy A copy of the map.
 * @return An integer value indicating the reachability status.
 */
int		check_array_reachability(t_container *pContainer, char **map_copy);

/**
 * @brief Checks the reachability of elements in the container.
 * 
 * This function checks if all elements in the container can be reached from a starting point.
 * 
 * @param pContainer A pointer to the container.
 * @return Returns an integer indicating the reachability status:
 *         - 0 if all elements are reachable.
 *         - 1 if there are unreachable elements.
 */
int		check_reachability(t_container *pContainer);

/**
 * @brief Checks the validity of the map.
 * 
 * This function checks if the map stored in the given container is valid.
 * It performs various checks to ensure that the map meets certain criteria.
 * 
 * @param pContainer A pointer to the container structure that holds the map.
 * @return Returns an integer value indicating the validity of the map.
 *         - 1 if the map is valid.
 *         - 0 if the map is invalid.
 */
int		check_map_validity(t_container *pContainer);

/**
 * @brief Checks if a string ends with a newline character.
 * 
 * @param s The string to check.
 * @return Returns 1 if the string ends with a newline character, 0 otherwise.
 */
int		check_newline(char *s);

/**
 * @brief Retrieves a line from a file specified by the given path.
 * This function reads a line from a file and returns it as a string.
 * The file is specified by the path parameter.
 * @param s The string to check.
 * @return Returns 1 if the string ends with a newline character, 0 otherwise.
 */
char	*get_line(char *path);

/**
 * @brief Retrieves a matrix from a file specified by the given path.
 * 
 * @param path The path to the file containing the matrix.
 * @return A pointer to a 2D array representing the matrix.
 */
char	**get_mtx(char *path);

/**
 * @brief Determines the position of the player in the matrix.
 * @param mtx The matrix representing the game board.
 * @return The position of the player as a t_axis structure.
 */
t_axis	player_position(char **mtx);

/**
 * @brief Determines the position of the exit in the matrix.
 * @param mtx The matrix representing the game board.
 * @return The position of the exit as a t_axis structure.
 */
t_axis	exit_potision(char **mtx);

/**
 * @brief Determines the position of the collectible in the matrix.
 * @param mtx The matrix representing the game board.
 * @return The position of the collectible as a t_axis structure.
 */
t_axis	*collectibles_position(char **mtx, t_container *pContainer);

/**
 * @brief Determines the position of the enemy in the matrix.
 * @param mtx The matrix representing the game board.
 * @return The position of the enemy as a t_axis structure.
 */
t_axis	*enemies_position(char **mtx, t_container *pContainer);

/**
 * @brief Handles the movement of the player.
 * This function is responsible for handling the movement of the player based on the provided keycode.
 * @param keycode The keycode representing the direction of movement.
 * @param pContainer A pointer to the container struct.
 */
void	handle_player_movement(int keycode, t_container *pContainer);

/**
 * @brief Handles the movement of the enemy.
 * This function is responsible for handling the movement of the enemy based on the provided keycode.
 * @param pContainer A pointer to the container struct.
 */
void	handle_enemy_movement(t_container *pContainer);

/**
 * @brief Handles the collection of collectibles.
 * This function is responsible for handling the collection of collectibles by the player.
 * @param pCont A pointer to the container struct.
 */
void	handle_collectibles(t_container *pCont);

/**
 * @brief Handles the win condition.
 * This function is responsible for handling the win condition of the game.
 * @param pCont A pointer to the container struct.
 */
void	handle_win(t_container *pCont);

/**
 * @brief Handles the death condition.
 * This function is responsible for handling the death condition of the game.
 * @param pCont A pointer to the container struct.
 */
void	handle_death(t_container *pCont);

/**
 * @brief Check if the block next to the player is walkable.
 * @param pCont A pointer to the container struct.
 */
int		is_walkable(int keycode, t_container *pContainer);

/**
 * @brief Check if the player can move one block in the given direction.
 * @param pContainer A pointer to the container struct.
 */
void	parse_move_up(int keycode, t_container *pContainer);

/**
 * @brief Check if the player can move one block in the given direction.
 * @param pContainer A pointer to the container struct.
 */
void	parse_move_right(int keycode, t_container *pContainer);

/**
 * @brief Check if the player can move one block in the given direction.
 * @param pContainer A pointer to the container struct.
 */
void	parse_move_down(int keycode, t_container *pContainer);

/**
 * @brief Check if the player can move one block in the given direction.
 * @param pContainer A pointer to the container struct.
 */
void	parse_move_left(int keycode, t_container *pContainer);

/**
 * @brief Prints an error message to the standard error output.
 * @param error_type The type of error to print.
 * @return Returns an integer value indicating the error type.
 */
int		print_error(t_error error_type);

/**
 * @brief Prints the HUD for the program.
 */
void	print_stats(t_container *pContainer);

/**
 * @brief Prints the game start message.
 */
void	print_game_start(void);

/**
 * @brief Checks the arguments passed to the program.
 * This function verifies the number of arguments passed to the program and validates the map file.
 * @param ac The number of command-line arguments.
 * @param map_file The path to the map file.
 * @return Returns 0 if the arguments are valid, otherwise returns a non-zero value.
 */
int		check_args(int ac, char *map_file);

/**
 * @brief Checks if the given character is a valid element in the game map.
 * This function checks if the character is a valid element that can be present in the game map.
 * @param c The character to be checked.
 * @return Returns an integer value indicating whether the character is a valid element (1) or not (0).
 */
int		check_element(char c);

/**
 * @brief Checks the number of elements in the game map.
 * This function counts the number of elements in the game map and returns the count.
 * @param map The game map represented as a 2D array of characters.
 * @return Returns an integer value indicating the number of elements in the game map
*/
int		check_elem_number(char **map);

/**
 * @brief Assigns the exit position in the game container.
 * This function is responsible for assigning the exit position in the game container.
 * @param pContainer A pointer to the game container.
 * @return void
 */
void	assign_exit(t_container *pContainer);

/**
 * @brief Executes the game based on the given keycode and container.
 * @param keycode The key code representing the user input.
 * @param pContainer A pointer to the container structure.
 * @return An integer representing the game status.
 */
int		execute_game(int keycode, t_container *pContainer);

#endif