#include "libft.h"

static	int	ft_strptrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_strptrjoin(char **s1, char**s2)
{
	char	**p;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len1 = ft_strptrlen(s1);
	len2 = ft_strptrlen(s2);
	p = (char **)malloc(sizeof(char *) * (len1 + len2 + 1));
	if (p == NULL)
		return (NULL);
	while (j < len1)
		p[i++] = s1[j++];
	j = 0;
	while (j < len2)
		p[i++] = s2[j++];
	p[i] = NULL;
	return (p);
}
