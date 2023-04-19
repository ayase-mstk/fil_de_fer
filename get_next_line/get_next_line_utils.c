/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:48:31 by mahayase          #+#    #+#             */
/*   Updated: 2023/02/23 14:48:31 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	ft_strcheck(const char *s, char c)
{
	ssize_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *src)
{
	char	*p;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(src);
	p = malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t len2)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	len1;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	if (!len1 && !len2)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (p == NULL)
		return (NULL);
	if (s1)
		while (j < len1)
			p[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

char	*ft_free(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}
