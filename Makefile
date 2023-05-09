NAME = fdf

SRCS = main2.c \
		transform.c \
		mlx.c \
		error.c \
		ft_atof.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		list/lst_print.c \
		# list/lst_free.c \
		# list/lst_init.c \
		# list/lst_last.c \
		# list/lst_pushback.c \
		# list/lst_size.c \

OBJS = $(SRCS:%.c=%.o)

LIBFT_DIR  = libft
PRINTF_DIR = libftprintf
LIBS       = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

# MLX_DIR = minilibx_mms_20200219
MLX_LINUX_DIR = minilibx-linux
MLX_FNAME	=	libmlx.a
MLX	=	$(MLX_LINUX_DIR)/$(MLX_FNAME)
MLX_MAKE	=	make -C $(MLX_LINUX_DIR)
X11_DIR	=	/usr/X11
INCLUDES	=	-I$(MLX_LINUX_DIR) -I$(X11_DIR)/include

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address # delete sanitizer
RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -lm $(INCLUDES) -L $(MLX_LINUX_DIR) -lmlx -L$(X11_DIR)/lib -lXext -lX11 -o $(NAME) $(OBJS) $(LIBS)
# $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLX_DIR)/libmlx.dylib

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