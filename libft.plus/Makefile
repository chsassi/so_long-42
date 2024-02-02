NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEADERS)
COMPILE = $(CC) $(CFLAGS) -c 
ARCHIVE = ar rc $(NAME)
HEADERS = ./headers

CHAR_HAND = ./char.handling
CONVERSIONS = ./conversions
PRINTF = ./ft_printf
GET_NEXT_LINE = ./get_next_line
LIST_HAND = ./list.handling
MATRIX_HAND = ./matrix.handling
MEMORY_HAND = ./memory.handling
PRINTS = ./prints
STRING_HAND = ./string.handling
EVERY_INCLUDES = -I. -I$(CHAR_HAND) -I$(CONVERSIONS) -I$(LIST_HAND) \
					-I$(MATRIX_HAND) -I$(MEMORY_HAND) -I$(PRINTS) \
					-I$(STRING_HAND) \


GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC = $(CHAR_HAND)/ft_isalnum.c \
		$(CHAR_HAND)/ft_isalpha.c \
		$(CHAR_HAND)/ft_isascii.c \
		$(CHAR_HAND)/ft_isdigit.c \
		$(CHAR_HAND)/ft_isprint.c \
		$(CHAR_HAND)/ft_tolower.c \
		$(CHAR_HAND)/ft_toupper.c \
		$(CONVERSIONS)/ft_atoi.c \
		$(CONVERSIONS)/ft_itoa.c \
		$(CONVERSIONS)/ft_putnbr_fd.c \
		$(LIST_HAND)/ft_lstadd_back.c \
		$(LIST_HAND)/ft_lstadd_front.c \
		$(LIST_HAND)/ft_lstclear.c \
		$(LIST_HAND)/ft_lstdelone.c \
		$(LIST_HAND)/ft_lstiter.c \
		$(LIST_HAND)/ft_lstlast.c \
		$(LIST_HAND)/ft_lstmap.c \
		$(LIST_HAND)/ft_lstnew.c \
		$(LIST_HAND)/ft_lstsize.c \
		$(MATRIX_HAND)/count_mtx_elements.c \
		$(MATRIX_HAND)/memory_management.c \
		$(MATRIX_HAND)/search.c \
		$(MEMORY_HAND)/ft_calloc.c \
		$(MEMORY_HAND)/ft_memchr.c \
		$(MEMORY_HAND)/ft_memcmp.c \
		$(MEMORY_HAND)/ft_memcpy.c \
		$(MEMORY_HAND)/ft_memmove.c \
		$(MEMORY_HAND)/ft_memset.c \
		$(STRING_HAND)/ft_bzero.c \
		$(STRING_HAND)/ft_split.c \
		$(STRING_HAND)/ft_strchr.c \
		$(STRING_HAND)/ft_strdup.c \
		$(STRING_HAND)/ft_striteri.c \
		$(STRING_HAND)/ft_strjoin.c \
		$(STRING_HAND)/ft_strlcat.c \
		$(STRING_HAND)/ft_strlcpy.c \
		$(STRING_HAND)/ft_strlen.c \
		$(STRING_HAND)/ft_strmapi.c \
		$(STRING_HAND)/ft_strncmp.c \
		$(STRING_HAND)/ft_strnstr.c \
		$(STRING_HAND)/ft_strrchr.c \
		$(STRING_HAND)/ft_strtrim.c \
		$(STRING_HAND)/ft_substr.c \

OBJ = ${SRC:.c=.o}

all: PRINTF_COMP GNL_COMP $(NAME) 

$(NAME): $(OBJ) 
	$(COMPILE) $(SRC) $(EVERY_INCLUDES)
	@echo "$(BLUE)	LIBFT COMPILED! 📖✅$(RESET)"

PRINTF_COMP:
	$(MAKE) -C $(PRINTF)
	mv ./$(PRINTF)/libftprintf.a ./$(NAME)

GNL_COMP:
	$(MAKE) -C $(GET_NEXT_LINE)
	mv ./$(GET_NEXT_LINE)/libgnl.a ./$(NAME)

RM = rm -f

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ./*.o
	@$(RM) $(PRINTF)/*.o
	@$(RM) $(GET_NEXT_LINE)/*.o
	@echo "$(RED)	LIBFT DESTROYED! 📖✅$(RESET)"


re: fclean all $(PRINTF) $(GET_NEXT_LINE)

.SILENT:
.PHONY: all clean fclean re