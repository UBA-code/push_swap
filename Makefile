SRCS = check_utils.c ft_calloc.c ft_split.c ft_strdup.c ft_substr.c push_swap.c utils.c \
		create_stack.c
OBG = $(SRCS:.c=.o)
# CFLAGS = -Wall -Werror -Wextra
NAME = push_swap

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME)

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re