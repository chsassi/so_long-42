NAME = so_long

CC = cc
HEADER = ./libft.plus/headers
CFLAGS = -Wextra -Werror -Wall -g -I$(HEADER) -Imlx
COMPILE = $(CC) $(CFLAGS) -c 
ARCHIVE = ar rc $(NAME)

MINILIBX = ./mlx
LIBFT_DIR = ./libft.plus
MLX_A = -L$(MINILIBX) -lmlx
MLXFLAGS = -lX11 -lXext -lm

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC =   ./src/main.c \
		./src/init_game.c \
		./src/enemy_handling.c \
		./src/image_rendering.c \
		./src/position.c \
		./src/map_checks.c \
		./src/map_handling.c \
		./src/map_parsing.c \
		./src/movement_handling.c \
		./src/movement_checks.c \
		./src/endgame.c \
		./src/print_utils.c \
		./src/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft:
	make all -C $(LIBFT_DIR)


$(NAME): libft $(OBJ)
	make all -C $(MINILIBX)
	$(CC) $(CFLAGS) -I. -I$(HEADER) $(OBJ) $(MLX_A) $(MLXFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)	SO LONG COMPILED! 🚀✅$(RESET)"
	@echo "$(GREEN)	Run ./so_long maps/map(1, 2, 3, 4).ber $(RESET)"

RM = rm -f

clean:
	$(RM) $(OBJ)
	make clean -C $(MINILIBX)
	make clean -C $(LIBFT_DIR)

fclean: clean
	make clean -C $(MINILIBX)
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	@echo "$(RED)	SO LONG DESTROYED! 🗑️ $(RESET)"

re: fclean all