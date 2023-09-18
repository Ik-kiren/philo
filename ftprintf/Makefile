CFLAGS  = -Werror -Wextra -Wall
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_printf_hexa.c ft_printf_nbr.c
OBJS = $(SRCS:c=o)

all : $(NAME)

$(NAME) : $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(NAME)
	
fclean : clean
	rm -f $(OBJS)
	
re : fclean all

.PHONY : clean fclean re all