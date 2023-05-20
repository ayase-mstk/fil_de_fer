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

static	unsigned int	ft_check_num(char c, char *base1, char *base2)
{
	int	i;

	i = 0;
	while (base1[i])
	{
		if (c == base1[i] || c == base2[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base1, char *base2)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result *= 16;
		result += 0x0 + ft_check_num(str[i], base1, base2);
		i++;
	}
	return (result);
}
