NAME = gnl.a
HNAME = gnl.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
AR = ar rc $(NAME)

SRC =	./gnl.c \
		./gnl_utils.c \

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