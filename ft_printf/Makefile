NAME = libftprintf.a
HNAME = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
AR = ar rc $(NAME)

SRC =	./ft_printf.c \
		./ft_putchar.c \
		./ft_putstr.c \
		./ft_putnbr_base.c \
		./ft_putnbr_base_unsigned.c \
		./ft_putnbr_base_unsigned_long.c \
		./ft_putaddr.c \
		./ft_strlen.c \
		./ft_specifiers.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HNAME)
		@$(COMPILE) $(FLAG) -c $(SRC)
		@ar rc $(NAME) $(OBJ)

RM = rm -f

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean rm