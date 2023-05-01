NAME = libftprintf.a

SRCS = ft_printf.c print_char.c print_decimal.c \
		print_lowerhex.c print_pointer.c print_string.c \
		print_unsignedint.c print_upperhex.c print_other.c

OBJS = $(SRCS:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar crs

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re