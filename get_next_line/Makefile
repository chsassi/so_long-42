NAME = gnl.a
HNAME = get_next_line.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
AR = ar rc $(NAME)

SRC =	./get_next_line.c \
		./get_next_line_utils.c \
		./get_next_line_bonus.c \
		./get_next_line_utils_bonus.c \

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