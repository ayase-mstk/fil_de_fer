/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stbstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:23:49 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/10 16:33:45 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	memory;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		len = 0;
	if ((s_len - start) < len)
		memory = s_len - start + 1;
	else
		memory = len + 1;
	substr = (char *)malloc(sizeof(char) * memory);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < memory - 1)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char			s[] = "abcdefg";
// 	unsigned int	start= 2;
// 	size_t			len = 10;
// 	char	*p;
// 	int i;

// 	i = 0;
// 	p = ft_substr(s, start, len);
// 	while (p[i])
// 	{
// 		printf("[%c]\n", p[i]);
// 		i++;
// 	}
// 	printf("[%p]\n", p+i);
// 	return (0);
// }
