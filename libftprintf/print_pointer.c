/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:13:13 by mahayase          #+#    #+#             */
/*   Updated: 2023/02/01 14:13:15 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recursion_n(uintptr_t n)
{
	uintptr_t	n_mod;
	uintptr_t	n_div;
	char		c;

	n_div = n / 16;
	n_mod = n % 16;
	if (n_div != 0)
		ft_recursion_n(n_div);
	if (n_mod > 9)
	{
		c = (n_mod % 10) + 'a';
	}
	else
		c = n_mod + '0';
	write(1, &c, 1);
}

static ssize_t	number_of_digit(uintptr_t n)
{
	int	cnt;

	cnt = 2;
	if (n < 0)
		cnt++;
	while (n)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

ssize_t	print_pointer(uintptr_t n)
{
	write(1, "0x", 2);
	if (n == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	ft_recursion_n(n);
	return (number_of_digit(n));
}
