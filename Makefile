NAME = fdf

SRCS = 	main.c \
		utils.c \
		utils2.c \
		init.c \
		free.c \
		read_map.c \
		position.c \
		transform.c \
		draw.c \
		switch.c \
		color.c \
		hooks.c \
		bonus_hooks.c \
		error.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)

LIBFT_DIR  = libft
PRINTF_DIR = libftprintf
LIBS       = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

MLX_LINUX_DIR = minilibx-linux
MLX_FNAME	=	libmlx.a
MLX	=	$(MLX_LINUX_DIR)/$(MLX_FNAME)
MLX_MAKE	=	make -C $(MLX_LINUX_DIR)
X11_DIR	=	/usr/X11
INCLUDES	=	-I$(MLX_LINUX_DIR) -I$(X11_DIR)/include

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -lm $(INCLUDES) -L $(MLX_LINUX_DIR) -lmlx -L$(X11_DIR)/lib -lXext -lX11 -o $(NAME) $(OBJS) $(LIBS)

.c.o :
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re