/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:34:14 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/19 18:34:16 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;

	i = ft_strlen(s) - 1;
	if (!c)
		return ((char *)&s[i + 1]);
	chr = (char)c;
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		if (!(s[i]))
			break ;
		i--;
	}
	return (NULL);
}
