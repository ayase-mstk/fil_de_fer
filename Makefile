NAME = fdf

SRCS = main.c \
		error.c \
		list/lst_free.c \
		list/lst_init.c \
		list/lst_last.c \
		list/lst_print.c \
		list/lst_pushback.c \
		list/lst_size.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

OBJS = $(SRCS:%.c=%.o)

LIBFT_DIR  = libft
PRINTF_DIR = libftprintf
MLX_DIR = minilibx_mms_20191025_beta
LIBS       = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf


CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLX_DIR)/libmlx.dylib

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re