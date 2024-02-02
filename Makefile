NAME = so_long
NAME_A = libso_long.a

CC = cc
CFLAGS = -Wextra -Werror -Wall -g
ARCHIVE = ar rc $(NAME)
RM = rm -f

MINILIBX = ./mlx
LIBFT_DIR = ./libft.plus
LIBFT_A = ./libft.a
MLX_A = $(MINILIBX)/libmlx.a
MLXFLAGS = -lX11 -lXext -lm
HEADER = ./libft.plus/headers

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

all: $(NAME_A)

$(NAME_A): mlx_comp Libft_comp $(OBJ)
	$(CC) $(CFLAGS) -I. -I$(HEADER) $(OBJ) -o $(NAME) $(MLX_A) $(MLXFLAGS) -L. -lso_long
	@echo "$(GREEN)		Game compiled! 🚀✅$(RESET)"

mlx_comp:
	make -C $(MINILIBX)
Libft_comp:
	make all -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ)
	make clean -C $(MINILIBX)
	make clean -C $(LIBFT_DIR)

fclean: clean
	make clean -C $(MINILIBX)
	make fclean -C $(LIBFT_DIR)

	$(RM) $(NAME) $(NAME_A)

re: fclean all