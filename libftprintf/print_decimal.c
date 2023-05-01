/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:32:55 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/25 21:32:57 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static void	ft_recursion_n(int n)
{
	int		n_mod;
	int		n_div;
	char	c;

	n_div = n / 10;
	n_mod = ft_abs(n % 10);
	if (n_div != 0)
		ft_recursion_n(n_div);
	c = n_mod + '0';
	write(1, &c, 1);
}

static ssize_t	number_of_digit(int n)
{
	ssize_t	cnt;

	cnt = 0;
	if (n < 0)
		cnt++;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

ssize_t	print_decimal(int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 0)
		write (1, "-", 1);
	ft_recursion_n(n);
	return (number_of_digit(n));
}
