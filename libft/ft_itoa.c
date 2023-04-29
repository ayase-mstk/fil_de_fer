/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:14:10 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/13 13:15:14 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	put_in(int n, char *str, size_t len)
{
	int	tmp;

	while (n)
	{
		tmp = n % 10;
		str[len--] = -tmp + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = ft_intlen(n);
	if (n <= 0)
		len++;
	str = (char *)malloc(sizeof(char) *(len + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		ft_strlcpy(str, "0", 2);
		return (str);
	}
	str[len--] = '\0';
	if (n < 0)
		str[0] = '-';
	else
		n *= -1;
	put_in(n, str, len);
	return (str);
}
