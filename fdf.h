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
// #include "./minilibx_mms_20191025_beta/mlx.h"
// #include "X11/keysym.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846

# endif

typedef struct s_mappoint
{
	double				x;
	double				y;
	double				z;
	double				vx;
	double				vy;
	double				vz;
	uint32_t			color;
}	t_mappoint;

typedef struct s_map
{
	t_mappoint	**array;
	int			row;
	int			col;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

void		lst_free(t_map *map);
t_map		*lst_init(void);
t_mappoint	*lst_last(t_map *map);
void		lst_print(t_map *map);
void		lst_pushback(t_map *map, double x, double y, double z);
size_t		lst_size(t_map *map);

double	ft_atof(const char *nptr);
void	ft_rotation_z(t_map *map, double theeta);
void	ft_mlx(t_map *map);
int		main(int ac, char **av);

#endif