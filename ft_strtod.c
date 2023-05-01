#include "fdf.h"

double	ft_strtod(const char* restrict s, char **restrict endptr)
{
	double		result;
	int			sign;
	int			i;
	int			j;

	result = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	j = i;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
			i++;
		}
	}
	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;
		if (s[i] == '-')
		{
			i++;
			while (s[i] >= '0' && s[i] <= '9')
			{
				result = result * 10 + (s[i] - '0');
				i++;
			}
			result = result * pow(10, -i + j);
		}
		else if (s[i] == '+')
		{
			i++;
			while (s[i] >= '0' && s[i] <= '9')
			{
				result = result * 10 + (s[i] - '0');
				i++;
			}
			result = result * pow(10, i - j);
		}
	}
	if (endptr)
		*endptr = (char *)&s[i];
	return (result * sign);
}

// restrict: restrict keyword is a declaration of intent given by the programmer to the compiler.
// It says that for the lifetime of the pointer, only it or a value directly derived from it (such as pointer + 1) 
// will be used to access the object to which it points. This limits the effects of pointer aliasing, aiding optimizations. 
// If the declaration of intent is not followed and the object is accessed by an independent pointer, this will result in undefined behavior of the program.

// double型のサイズは8バイトで、絶対値の最大値は1.797693e+308、最小値は2.225074e-308となります。
// printf関数などを使って出力表示する際の変換指定子は「lf」(long float)になります。