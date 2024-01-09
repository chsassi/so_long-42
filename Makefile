NAME = so_long
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
RM = rm -f

LINKS_LINUX = -lX11 -lm -lXext
MINILIBX = mlx/libmlx.a
PRINTF = ft_printf/libftprintf.a

SRC = map_rendering.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): mlx_comp printf_comp comp

mlx_comp:
	make -C mlx/
printf_comp:
	make -C ft_printf/

comp:
	$(CC) $(CFLAGS) $(SRC) $(MINILIBX) $(PRINTF) $(LINKS_LINUX) -o $(NAME)
	@echo "Compiled ✅\033[0;37m"

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C mlx/
	make clean -C ft_printf/

	$(RM) $(NAME)

re: fclean all