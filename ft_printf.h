/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:18:13 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/05 20:17:03 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_params
{
	bool	flag_minus;
	bool	flag_zero;
	size_t	width;
	size_t	precision;
}		t_p;

typedef struct s_counters
{
	int		counter;
	int		length;
}		t_c;

int		ft_printf(const char *format, ...);

void	start_counters(t_c *counters);

void	start_struct(t_p *print_data);

void	get_data(const char *data, va_list args, t_c *count);

size_t	get_flags_and_precision(char *data, va_list args, t_p *print_data);

size_t	ft_isalpha(size_t c);

size_t	ft_isdigit(size_t c);

size_t	get_precision(const char *data, t_p *print_data, va_list args);

size_t	get_flags(const char *data, va_list args, t_p *print_data);

int		get_width(const char *data, t_p *print_data);

void	get_type(const char *data, va_list args, t_p *print, t_c *count);

void	ft_putchar_fd(char c, int fd);

void	print_char(va_list args, t_p *print_data, t_c *count);

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

void	ft_putstr_fd(char *s, int fd);

size_t	ft_isflag(size_t str);

size_t	ft_strlen(char *s);

int		get_size_int(long int value);

void	print_percent(t_p *print_data, t_c *count);

void	print_null(t_c *count);

size_t	print_int(va_list args, t_p *print_data, t_c *count);

char	*ft_itoa(size_t n);

size_t	print_string(va_list args, t_p *print_data, t_c *count);

void	ft_putchar_sized(char *s, int fd, size_t size);

#endif
