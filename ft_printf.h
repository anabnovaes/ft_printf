/* ************************************************************************** */
/*                                      */
/*                            :::   ::::::::  */
/*  ft_printf.h                    :+:   :+:  :+:  */
/*                          +:+ +:+     +:+   */
/*  By: apaula-b <apaula-b@student.42sp.org.br>  +#+ +:+    +#+    */
/*                        +#+#+#+#+#+  +#+      */
/*  Created: 2021/05/21 11:18:13 by apaula-b     #+#  #+#       */
/*  Updated: 2021/09/12 00:26:12 by apaula-b     ###  ########.fr    */
/*                                      */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_counters
{
	int		counter;
	int		length;
}		t_c;

int			ft_printf(const char *format, ...);

void		start_counters(t_c *counters);

void		get_type(const char *data, va_list args, t_c *count);

void		ft_putchar_fd(char c, int fd);

void		print_char(va_list args, t_c *count);

int			ft_atoi(const char *str);

void		ft_bzero(void *s, size_t n);

void		*ft_calloc(size_t count, size_t size);

void		ft_putstr_fd(char *s, t_c *count);

size_t	ft_strlen(char *s);

int			get_size_int(long int value);

void		print_percent( t_c *count);

void		print_null(t_c *count);

size_t	print_int(va_list args, t_c *count, const char *type);

size_t	print_string(va_list args, t_c *count);

size_t	print_hexa(va_list args, t_c *count, const char *data);

size_t	print_pointer(va_list args, t_c *count);

char		*convert_int(va_list args, const char *type);

char		*ft_itoa(int n);

char		*ft_itoa_unsigned(unsigned int n);


char		*ft_utoa(unsigned int integer);

char		*ft_utoa_long(unsigned long integer);

char		*ft_toupper(char *c);

#endif
