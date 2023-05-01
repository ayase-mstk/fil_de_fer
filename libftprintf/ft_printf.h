/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:12:51 by mahayase          #+#    #+#             */
/*   Updated: 2023/02/01 14:12:53 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
ssize_t	print_char(int c);
ssize_t	print_decimal(int n);
ssize_t	print_lowerhex(unsigned int n);
ssize_t	print_pointer(uintptr_t n);
ssize_t	print_string(char *str);
ssize_t	print_unsignedint(unsigned int n);
ssize_t	print_upperhex(unsigned int n);
ssize_t	print_other(int c);

#endif
