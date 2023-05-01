#include "fdf.h"

static double	ft_pow(double x, double y)
{
	double	result;
	double		i;

	i = 0.0;
	result = 1.0;
	while (i < y)
	{
		result *= x;
		i++;
	}
	return (result);
}

double	ft_atof(const char *nptr)
{
	bool	flag;
	double	result;
	double 	sign;
	double	scale;
	double	psign;
	double	p;

	result = 0.0;
	sign = 1.0;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		nptr++;
		sign = -1.0;
	}
	if (ft_isdigit((unsigned char) *nptr))
	{
		flag = true;
		do
		{
			result = result * 10.0 + (double) (*nptr - '0');
			nptr++;
		} while (ft_isdigit((unsigned char) *nptr));
	}
	if (*nptr == '.')
	{
		flag = false;
		nptr++;
		if (ft_isdigit((unsigned char) *nptr))
		{
			scale = 0.1;
			flag = true;
			do
			{
				result += scale * (double) (*nptr - '0');
				scale *= 0.1;
				nptr++;
			} while (ft_isdigit((unsigned char) *nptr));
		}
	}
	if (flag && (*nptr == 'e' || *nptr == 'E'))
	{
		nptr++;
		flag = false;
		psign = +1.0;
		if (*nptr == '+')
			nptr++;
		else if (*nptr == '-')
		{
			nptr++;
			psign = -1.0;
		}
		if (ft_isdigit((unsigned char) *nptr))
		{
			flag = true;
			p = 0.0;
			do
			{
				p = p * 10.0 + (*nptr - '0');
				nptr++;
			} while (ft_isdigit((unsigned char) *nptr));
			result *= ft_pow(10.0, psign * p);
		}
	}
	return (sign * result);
}