/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:18:13 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/28 22:05:32 by apaula-b         ###   ########.fr       */
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
}		t_params;

int		ft_printf(const char *format, ...);

void	start_struct(t_params **print_data);

int		get_data_and_print(const char *data, va_list args, int *response);

size_t	get_flags_and_precision(char *data, va_list args, t_params *print_data);

size_t	ft_isalpha(size_t c);

size_t	ft_isdigit(size_t c);

size_t	get_precision(const char *data, t_params **print_data, va_list args);

size_t	get_width(const char *data, t_params **print_data);

size_t	get_flags(const char *data, va_list args, t_params **print_data);

int		get_type_and_print(const char *data, va_list args);

void	ft_putchar_fd(char c, int fd);

int		print_char(va_list args);

size_t	ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

size_t	ft_isflag(const char *str);

#endif
