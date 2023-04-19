/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:48:32 by mahayase          #+#    #+#             */
/*   Updated: 2023/02/23 14:48:32 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
ssize_t	ft_strcheck(const char *s, char c);
char	*ft_strdup(char *src);
char	*ft_strnjoin(char const *s1, char const *s2, size_t len2);
char	*ft_free(char *str);
char	*get_next_line(int fd);

#endif
