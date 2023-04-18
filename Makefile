NAME = fdf

SRCS = main.c

OBJS = $(SRCS:%.c=%.o)

BONUS = 

BONUS_OBJS = $(BONUS:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar crs

ifdef WITH_BONUS
	SRCS += $(BONUS)
	OBJS += $(BONUS_OBJS)
endif

all:	$(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:
	make WITH_BONUS=1

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all