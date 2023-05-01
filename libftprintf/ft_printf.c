/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:12:32 by mahayase          #+#    #+#             */
/*   Updated: 2023/02/01 14:12:34 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	check_format(const char *s, va_list ap)
{
	size_t	i;

	i = 0;
	if (s[i] == 'c')
		return (print_char(va_arg(ap, int)));
	else if (s[i] == 's')
		return (print_string(va_arg(ap, char *)));
	else if (s[i] == 'p')
		return (print_pointer(va_arg(ap, uintptr_t)));
	else if (s[i] == 'd' || s[i] == 'i')
		return (print_decimal(va_arg(ap, int)));
	else if (s[i] == 'u')
		return (print_unsignedint(va_arg(ap, unsigned int)));
	else if (s[i] == 'x')
		return (print_lowerhex(va_arg(ap, unsigned int)));
	else if (s[i] == 'X')
		return (print_upperhex(va_arg(ap, unsigned int)));
	else if (s[i] == '%')
		return (print_char(s[i]));
	else
		return (print_other(s[i]));
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	ssize_t	sum;
	size_t	i;

	sum = 0;
	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			sum += check_format(s + i + 1, ap);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			sum++;
		}
		i++;
		if (sum >= INT_MAX)
			return (-1);
	}
	va_end(ap);
	return ((int)sum);
}

// #include <stdio.h>
// #include <assert.h>
// int	main(void)
// {
	// int		digit;
// 	char	str[] = "abcde";

// 	digit = ft_printf("%c\n", 'a');
// 	printf("%d\n", digit);
// 	digit = printf("%c\n", 'a');
// 	printf("%d\n\n", digit);

	// digit = ft_printf("%s %s %s\n", str, "", NULL);
	// printf("%d\n", digit);
	// digit = printf("%s %s %s\n", str, "", NULL);
	// printf("%d\n\n", digit);

	// digit = ft_printf("%d %d %d\n", INT_MAX, INT_MIN, UINT_MAX + 1);
	// printf("%d\n", digit);
	// digit = printf("%d %d %d\n", INT_MAX, INT_MIN, UINT_MAX + 1);
	// printf("%d\n\n", digit);

	// digit = ft_printf("%i %i\n", INT_MAX, INT_MIN);
	// printf("%d\n", digit);
	// digit = printf("%i %i\n", INT_MAX, INT_MIN);
	// printf("%d\n\n", digit);

// 	digit = ft_printf("%x %x\n", UINT_MAX, INT_MAX);
// 	printf("%d\n", digit);
// 	digit = printf("%x %x\n", UINT_MAX, INT_MAX);
// 	printf("%d\n\n", digit);

// 	digit = ft_printf("%X %X\n", UINT_MAX, INT_MAX);
// 	printf("%d\n", digit);
// 	digit = printf("%X %X\n", UINT_MAX, INT_MAX);
// 	printf("%d\n\n", digit);

// 	digit = ft_printf("%%\n");
// 	printf("%d\n", digit);
// 	digit = printf("%%\n");
// 	printf("%d\n\n", digit);

// 	int		n = 10;
// 	int		*p1 = &n;
// 	char 	*p2 = NULL;
// 	char	*p3 = str;
// 	digit = ft_printf("%p %p %p\n", p1, p2, p3);
// 	printf("%d\n", digit);
// 	digit = printf("%p %p %p\n", p1, p2, p3);
// 	printf("%d\n\n", digit);

// 	digit = ft_printf("%u %u\n", UINT_MAX, INT_MAX);
// 	printf("%d\n", digit);
// 	digit = printf("%u %u\n", UINT_MAX, INT_MAX);
// 	printf("%d\n\n", digit);
	// int		ret = 0;
// int		ret2 = 0;
// 	char	*s = (char *)malloc(sizeof(char) * 2147483647);
// 	memset(s, 'c', 2147483647);
// 	ret = printf("%s", s);
// 	ret2 = ft_printf("%s", s);
// 	printf("%d", ret2);
// 	assert(ret == ret2);
// 	ret = printf("[%d] [%%] % \n", INT_MIN);
// 	ret2 = ft_printf("[%d] [%%] % \n", INT_MIN);
// 	assert(ret == ret2);
// 	return (0);
// }