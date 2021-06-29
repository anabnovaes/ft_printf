/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:18:13 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/29 20:57:09 by apaula-b         ###   ########.fr       */
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

size_t	get_width(const char *data, t_p *print_data);

size_t	get_flags(const char *data, va_list args, t_p *print_data);

void	get_type(const char *data, va_list args, t_p *print, t_c *count);

void	ft_putchar_fd(char c, int fd);

void	print_char(va_list args, t_p *print_data, t_c *count);

size_t	ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

size_t	ft_isflag(const char *str);

#endif
