#include "fdf.h"

void	put_errormessage(char *str)
{
	ft_putstr_fd(str, 2);
	exit (0);
}
