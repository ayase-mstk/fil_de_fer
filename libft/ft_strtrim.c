/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:35:42 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/11 18:33:10 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strstr(char const *charset, char to_find)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_startpoint(char const *str, char const *charset)
{
	size_t	i;

	i = 0;
	while (ft_strstr(charset, str[i]) != 0 && str[i])
		i++;
	return (i);
}

static size_t	ft_endpoint(char const *str, char const *charset)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (ft_strstr(charset, str[i]) == 1)
		i--;
	return (i + 1);
}

static char	*ft_strndup(char const *src, size_t size)
{
	char		*p;
	size_t		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (NULL);
	while (i < size)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*trim;

	if (!s1 || !set)
		return (NULL);
	if (!ft_strlen(set))
		return (ft_strdup((char *)s1));
	start = ft_startpoint(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_endpoint(s1, set);
	trim = ft_strndup(&s1[start], end - start);
	if (trim == NULL)
		return (NULL);
	return (trim);
}
