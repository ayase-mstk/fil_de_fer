#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_head
{
	t_point	*point;
}	t_head;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif