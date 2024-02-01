NAMEA = libso_long.a
NAME = so_long
HNAME = so_long.h
CC = cc
CFLAGS = -Wextra -Werror -Wall -g -I$(HEADERS)
ARCHIVE = ar rc $(NAME)
RM = rm -f

MINILIBX = ./mlx
LIBFT_DIR = ./libft.plus
HEADER = ./libft.plus/headers

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m

SRC =   ./main.c \
		./init.c \
		./map_handling.c \
		./image_rendering.c \
		./position.c \
		./movement.c \
		./parsing.c \
		./endgame.c \
		./map_checks.c \
		./utils.c \

OBJ = $(SRC:.c=.o)

all: mlx_comp Libft_comp $(NAMEA)

$(NAMEA): $(OBJ) -I$(HEADERS)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Game compiled! ✅🚀"

mlx_comp:
	make -C $(MINILIBX)
Libft_comp:
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C $(MINILIBX)
	make fclean -C $(LIBFT_DIR)

	$(RM) $(NAME) $(NAMEA)

re: fclean all