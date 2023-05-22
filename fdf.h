#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "libftprintf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "mlx.h"
# include "X11/keysym.h"
// # include "keymap.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846

# endif

# define HEIGHT	1080
# define WIDTH	1920
# define INDIGO 0x4b0082
# define BABYPINK 0xffb6c1
# define ROSEMIST 0xffe4e1

typedef enum e_color
{
	GRADATION,
	NORMAL
}	t_color;

typedef enum e_axis
{
	X,
	Y,
	Z
}	t_axis;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_range
{
	int	x_max;
	int	y_max;
	int	z_max;
	int	color_max;
	int	x_min;
	int	y_min;
	int	z_min;
	int	color_min;
}	t_range;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_bresenham
{
	t_point	extent;
	t_point	slope;
	double	error;
	double	delta;
}	t_bresenham;

typedef struct s_mappoint
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_mappoint;

typedef struct s_map
{
	t_mappoint	**array;
	t_mappoint	**para;
	t_mappoint	**iso;
	int			row;
	int			col;
	double		scale;
	double		zoom;
	int			move_x;
	int			move_y;
	t_axis		axis;
	double		theeta_x;
	double		theeta_y;
	double		theeta_z;
	t_color		color_mode;
	t_range		range;
	t_pos		pos;
	t_data		*data;
	t_img		*img;
}	t_map;

void			lst_print(t_map *map, t_mappoint **array);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				ft_abs(int n);
int				ft_slope(double a, double b);
int				ft_atoi_base(char *str, char *base1, char *base2);
void			put_errormessage(char *str);
t_map			*init_map(void);
void			init_mlx(t_map *map);
void			init_range(t_range *range);
void			malloc_iso(t_map *map);
void			init_iso(t_map *map);
void			free_strarr(char **strarr, int size);
void			free_map(t_map *map, int size);
void			free_iso(t_map *map, int size);
void			free_para(t_map *map, int size);
void			maparray_and_strarr_free(t_map *map, char **strarr, int size);
void			read_map(t_map *map, char *map_name);
void			split_map(t_map *map, char *lines[]);
void			store_map(t_map *map, char **strarr, int row);
void			ft_isometric_projection(t_map *map);
void			map_range(t_map *map, t_mappoint **array);
void			set_scale(t_map *map);
void			scale_points(t_map *map);
void			pos_set(t_map *map);
void			repos_xy(t_map *map, t_mappoint **array);
void			draw_image(t_map *map, t_mappoint **array);
void			draw_iso(t_map *map);
void			draw_para(t_map *map);
int				now_color(t_mappoint pre, t_mappoint now, \
							t_mappoint next, t_map *map);
void			set_hooks(t_map *map);
void			ft_zoom(int button, t_map *map);
void			zoom_points(t_map *map, t_mappoint **array);
void			ft_move(int key, t_map *map);
void			move_points(t_map *map, t_mappoint **array);
void			ft_rotate(int keycode, t_map *map);
void			ft_rotation(t_map *map, t_mappoint **array);
void			set_axis(int keycode, t_map *map);
void			ft_rotation_x(t_map *map, t_mappoint **array, double theeta);
void			ft_rotation_y(t_map *map, t_mappoint **array, double theeta);
void			ft_rotation_z(t_map *map, t_mappoint **array, double theeta);
int				main(int ac, char **av);

#endif