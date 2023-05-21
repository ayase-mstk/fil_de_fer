#include "fdf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_slope(double a, double b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}
