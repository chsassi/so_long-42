NAME = so_long
NAMEA = so_long.a
HNAME = so_long.h
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
ARCHIVE = ar rc $(NAME)
RM = rm -f
LINKS_LINUX = -lX11 -lm -lXext
MINILIBX = mlx/libmlx.a
LIBFT_DIR = Libft
FT_PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
EVERY_INCLUDE=-I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(GNL_DIR)

SRC =   ./main.c \
		./map_rendering.c \
		./image_rendering.c \
		./movement.c \
		./process_endgame.c \
		./utils.c

OBJ = $(SRC:.c=.o)

all: $(NAMEA)

$(NAMEA): mlx_comp ft_printf_comp Libft_comp gnl_comp comp $(OBJ)
	mv mlx/libmlx.a ./$(NAMEA)
	mv Libft/libft.a ./$(NAMEA)
	mv ft_printf/libftprintf.a ./$(NAMEA)
	mv get_next_line/gnl.a ./$(NAMEA)
	$(ARCHIVE) $(NAMEA) $(OBJ)
	$(CC) $(CFLAGS) $(EVERY_INCLUDE) main.c -L. -lso_long -o $(NAME)

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

	$(RM) $(NAME)

re: fclean all