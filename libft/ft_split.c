/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:34:15 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/10 14:34:47 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcount(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_cntsize(char	const *str, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (!str)
		return (cnt);
	while (str[i] != '\0' && i < ft_strlen(str))
	{
		start = i;
		end = start + ft_strcount(&str[i], c);
		if (end > start)
			cnt++;
		i = end + 1;
	}
	return (cnt);
}

static char	*ft_strndup(char const *src, size_t size)
{
	char	*p;
	size_t	i;

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

static char	**ft_free(char **strarr, char const *s)
{
	size_t	i;

	i = 0;
	while (strarr[i])
	{
		if (!s)
			break ;
		free(strarr[i]);
		i++;
	}
	if (strarr)
		free(strarr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	end;
	char	**strarr;

	i = 0;
	j = 0;
	strarr = (char **)malloc(sizeof(char *) * (ft_cntsize(s, c) + 1));
	if (strarr == NULL)
		return (NULL);
	while (j < ft_cntsize(s, c) && s[i] != '\0')
	{
		start = i;
		end = start + ft_strcount(&s[i], c);
		if (end > start)
		{
			strarr[j++] = ft_strndup(&s[start], end - start);
			if (strarr[j - 1] == NULL)
				return (ft_free(strarr, s));
		}
		i = end + 1;
	}
	strarr[j] = NULL;
	return (strarr);
}

// static size_t	ft_strcount(char const *str, char c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != c && str[i] != '\0')
// 		i++;
// 	return (i);
// }

// static size_t	ft_cntsize(char	const *str, char c)
// {
// 	size_t	i;
// 	size_t	start;
// 	size_t	end;
// 	size_t	cnt;

// 	i = 0;
// 	cnt = 0;
// 	if (!str)
// 		return (cnt);
// 	while (str[i] != '\0' && i < ft_strlen(str))
// 	{
// 		start = i;
// 		end = start + ft_strcount(&str[i], c);
// 		if (end > start)
// 			cnt++;
// 		i = end + 1;
// 	}
// 	return (cnt);
// }

// static char	*ft_strndup(char const *src, size_t size)
// {
// 	char	*p;
// 	size_t	i;

// 	i = 0;
// 	p = (char *)malloc(sizeof(char) * (size + 1));
// 	if (p == NULL)
// 		return (NULL);
// 	while (i < size)
// 	{
// 		p[i] = src[i];
// 		i++;
// 	}
// 	p[i] = '\0';
// 	return (p);
// }

// static char	**ft_free(char **strarr, char const *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (strarr[i])
// 	{
// 		if (!s)
// 			break ;
// 		free(strarr[i]);
// 		i++;
// 	}
// 	if (strarr)
// 		free(strarr);
// 	return (NULL);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	start;
// 	size_t	end;
// 	char	**strarr;

// 	i = 0;
// 	j = 0;
// 	strarr = (char **)malloc(sizeof(char *) * (ft_cntsize(s, c) + 1));
// 	if (!s || strarr == NULL)
// 		return (ft_free(strarr, s));
// 	while (j < ft_cntsize(s, c) && s[i] != '\0')
// 	{
// 		start = i;
// 		end = start + ft_strcount(&s[i], c);
// 		if (end > start)
// 		{
// 			strarr[j++] = ft_strndup(&s[start], end - start);
// 			if (strarr[j - 1] == NULL)
// 				return (ft_free(strarr, s));
// 		}
// 		i = end + 1;
// 	}
// 	strarr[j] = NULL;
// 	return (strarr);
// }

// int main(void)
// {
// 	char	*s = "      split       this for   me  !       ";

// 	printf("%p\n", ft_split(s, ' '));
// }
