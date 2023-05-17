#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "libftprintf/ft_printf.h"
# include "gnl/get_next_line.h"
// #include "X11/keysym.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846

# endif

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

typedef struct s_xy
{
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
}	t_xy;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_mappoint
{
	double			x;
	double			y;
	double			z;
	double			vx;
	double			vy;
	unsigned int	color;
	unsigned int	vcolor;
}	t_mappoint;

typedef struct s_map
{
	t_mappoint	**array;
	int			row;
	int			col;
	t_xy		xy;
	t_pos		pos;
	t_data		*data;
	t_img		*img;
}	t_map;

void			lst_print(t_map *map);
unsigned int	ft_atoi_base(char *str, char *base1, char *base2);
double			ft_atof(const char *nptr);
void			put_errormessage(char *str);
void			read_map(t_map *map, char *map_name);
void			split_map(t_map *map, char *lines[]);
void			store_map(t_map *map, char **strarr, int row);
void			free_strarr(char **strarr);
void			free_map(t_map *map);
void			maparray_and_strarr_free(t_map *map, char **strarr);
void			map_range(t_map *map, double x, double y);
void			pos_set(t_map *map, int width, int height);
void			repos_xy(t_map *map);
void			ft_rotation_x(t_map *map, double theeta);
void			ft_rotation_y(t_map *map, double theeta);
void			ft_rotation_z(t_map *map, double theeta);
void			ft_isometric_projection(t_map *map);
void			ft_isometric1(t_map *map);
void			ft_isometric2(t_map *map);
void			ft_mlx(t_map *map);
int				main(int ac, char **av);

#endif