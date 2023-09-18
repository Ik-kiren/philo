CC = gcc -Werror -Wall -Wextra
NAME = philo
SRCS = philo.c init.c thread.c utils.c end.c death.c checker.c
OBJS = $(SRCS:c=o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C ftprintf
	$(CC) $(OBJS) ftprintf/libftprintf.a -o $(NAME)

clean:
	make clean -C ftprintf
	rm -f $(NAME)

fclean: clean
	make fclean -C ftprintf
	rm -f $(OBJS)

re: fclean all
	make re -C ftprintf

.PHONY: all clean fclean re