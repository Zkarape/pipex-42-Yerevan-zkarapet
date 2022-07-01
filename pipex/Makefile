NAME = pipex

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
