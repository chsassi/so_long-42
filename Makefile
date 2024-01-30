NAMEA = libso_long.a
NAME = so_long
HNAME = so_long.h
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
ARCHIVE = ar rc 
RM = rm -f
MINILIBX = ./mlx
LIBFT_DIR = ./Libft
FT_PRINTF_DIR = ./ft_printf
GNL_DIR = ./get_next_line
EVERY_INCLUDE= -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(GNL_DIR) -I$(MINILIBX)
EVERY_LIB= -L$(LIBFT_DIR) -L$(GNL_DIR) -lgnl -lft -L$(FT_PRINTF_DIR) -lftprintf  -L$(MINILIBX) -lmlx -lX11 -lm -lXext

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
		./flood_fill_test.c

OBJ = $(SRC:.c=.o)

all: $(NAMEA)

$(NAMEA): mlx_comp ft_printf_comp Libft_comp gnl_comp comp $(OBJ)
	$(CC) $(CFLAGS) $(EVERY_INCLUDE) $(OBJ) -o $(NAME) $(EVERY_LIB)

mlx_comp:
	make -C mlx/
Libft_comp:
	make -C Libft/
ft_printf_comp:
	make -C ft_printf/
gnl_comp:
	make -C get_next_line/

comp:
	@echo "Game compiled! ✅🚀\033[0;37m"

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C mlx/
	make fclean -C ft_printf/
	make fclean -C Libft/
	make fclean -C get_next_line/

	$(RM) $(NAME) $(NAMEA)

re: fclean all
