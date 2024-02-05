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

SRC =   ./main.c \
		./init.c \
		./map_handling.c \
		./image_rendering.c \
		./position.c \
		./movement.c \
		./parsing.c \
		./endgame.c \
		./map_checks.c \
		./utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft:
	make all -C $(LIBFT_DIR)

$(NAME): libft $(OBJ)
	make all -C $(MINILIBX)
	$(CC) $(CFLAGS) -I. -I$(HEADER) $(OBJ) $(MLX_A) $(MLXFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)		Game compiled! 🚀✅$(RESET)"

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