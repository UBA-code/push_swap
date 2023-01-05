SRCS = actions.c actions_2.c cases.c check_utils.c create_stack.c ft_calloc.c \
	ft_split.c ft_strdup.c ft_substr.c push_swap.c sort_three.c utils.c utils_2.c utils_3.c\
	sort_five.c last_sort.c
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