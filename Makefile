CC = gcc -Werror -Wall -Wextra
NAME = philo
SRCS = philo.c init.c thread.c utils.c end.c
OBJS = $(SRCS:c=o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re