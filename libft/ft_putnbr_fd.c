/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:39:21 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/19 18:39:23 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *a, char *b)
{
	char	ch;

	ch = *a;
	*a = *b;
	*b = ch;
}

static void	ft_rev_int_tab(char *tab, size_t size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (j - i > 0)
	{
		ft_swap((tab + i), (tab + j));
		i++;
		j--;
	}
}

static size_t	to_char(char *s, int nb)
{
	int		tmp;
	size_t	i;

	i = 0;
	while (nb)
	{
		tmp = nb % 10;
		s[i++] = -tmp + '0';
		nb /= 10;
	}
	s[i] = '\0';
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	s[13];
	size_t	i;
	size_t	j;

	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
		write(fd, "-", 1);
	else
		n *= -1;
	i = to_char(s, n);
	ft_rev_int_tab(s, i);
	j = 0;
	while (j < i)
	{
		write(fd, &s[j], 1);
		j++;
	}
}
