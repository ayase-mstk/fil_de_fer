/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:48:31 by mahayase          #+#    #+#             */
/*   Updated: 2023/02/23 14:48:31 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*put_in_save(char *buf, char *save, ssize_t size)
{
	char	*tmp;

	tmp = save;
	save = ft_strnjoin(tmp, buf, size);
	free(tmp);
	return (save);
}

char	*read_until_newline(int fd, char *save)
{
	char		*buf;
	ssize_t		read_ret;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + (size_t)1));
	if (buf == NULL)
		return (NULL);
	while (ft_strcheck(save, '\n') == -1)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret <= 0)
			break ;
		buf[read_ret] = '\0';
		save = put_in_save(buf, save, read_ret);
		if (save == NULL)
			break ;
	}
	ft_free(&buf);
	return (save);
}

char	*put_in_line(char *save)
{
	size_t	i;
	char	*line;

	i = 0;
	if (save == NULL)
		return (NULL);
	else if (save[0] == '\0')
		return (ft_free(&save));
	else
	{
		while (save[i] && save[i] != '\n')
			i++;
		line = malloc(sizeof(char) * (i + 2));
		if (line == NULL)
			return (ft_free(&save));
		line[i + 1] = '\0';
		while (i != 0)
		{
			line[i] = save[i];
			i--;
		}
		line[i] = save[i];
	}
	return (line);
}

char	*save_after_newline(char *save, char *line)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	tmp = save;
	while (line[i])
		i++;
	size = ft_strlen(&tmp[i]);
	save = malloc(sizeof(char) * (size + 1));
	if (save == NULL)
		return (ft_free(&tmp));
	while (tmp[i])
		save[j++] = tmp[i++];
	save[j] = '\0';
	free(tmp);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[257];
	char		*line;

	if (fd < 0 || fd >= 256 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	save[fd] = read_until_newline(fd, save[fd]);
	if (save[fd] == NULL)
		return (NULL);
	line = put_in_line(save[fd]);
	if (line == NULL)
		return (NULL);
	save[fd] = save_after_newline(save[fd], line);
	if (save[fd] == NULL)
		return (NULL);
	return (line);
}
