/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:01:24 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/10 16:01:27 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			minus;
	long int	ans;

	minus = 1;
	ans = 0;
	while (*str == ' ' || (9 <= (int)*str && (int)*str <= 13))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		if (minus == -1 && (ans > LONG_MAX / 10 || \
						(ans == LONG_MAX / 10 && *str - '0' > LONG_MAX % 10)))
			return ((int)LONG_MIN);
		if (minus == 1 && (ans > LONG_MAX / 10 || \
						(ans == LONG_MAX / 10 && *str - '0' > LONG_MAX % 10)))
			return ((int)LONG_MAX);
		ans = ans * 10 + (*str - '0');
		str++;
	}
	return ((int)(ans * minus));
}
