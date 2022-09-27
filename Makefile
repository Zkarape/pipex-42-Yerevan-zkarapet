NAME = pipex

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra -g -ggdb3

$(NAME): $(OBJS)
	cc $(OBJS) $(FLAGS) -o $(NAME)

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
