/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upperhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:13:51 by mahayase          #+#    #+#             */
/*   Updated: 2023/02/01 14:13:53 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recursion_n(unsigned int n)
{
	unsigned int	n_mod;
	unsigned int	n_div;
	char			c;

	n_div = n / 16;
	n_mod = n % 16;
	if (n_div != 0)
		ft_recursion_n(n_div);
	if (n_mod > 9)
	{
		c = (n_mod % 10) + 'A';
	}
	else
		c = n_mod + '0';
	write(1, &c, 1);
}

static ssize_t	number_of_digit(unsigned int n)
{
	ssize_t	cnt;

	cnt = 0;
	if (n < 0)
		cnt++;
	while (n)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

ssize_t	print_upperhex(unsigned int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_recursion_n(n);
	return (number_of_digit(n));
}
