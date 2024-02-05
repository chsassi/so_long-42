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
		./src/init.c \
		./src/map_handling.c \
		./src/image_rendering.c \
		./src/position.c \
		./src/movement.c \
		./src/parsing.c \
		./src/endgame.c \
		./src/map_checks.c \
		./src/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft:
	make all -C $(LIBFT_DIR)


$(NAME): libft $(OBJ)
	make all -C $(MINILIBX)
	$(CC) $(CFLAGS) -I. -I$(HEADER) $(OBJ) $(MLX_A) $(MLXFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)	SO LONG COMPILED! 🚀✅$(RESET)"

RM = rm -f

clean:
	$(RM) $(OBJ)
	make clean -C $(MINILIBX)
	make clean -C $(LIBFT_DIR)

fclean: clean
	make clean -C $(MINILIBX)
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all