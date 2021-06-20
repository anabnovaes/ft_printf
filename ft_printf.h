/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:18:13 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/20 18:55:43 by apaula-b         ###   ########.fr       */
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

void	start_struct(t_params *print_data);

void	get_data_and_print(char *data, va_list args, int *response);

size_t	get_flags_and_precision(char *data, va_list args, t_params *print_data);

size_t	ft_isalpha(size_t c);

size_t	ft_isdigit(size_t c);

size_t	get_precision(char *data, t_params *print_data, va_list args);

size_t	get_width(char *data, t_params *print_data);

void	ft_putchar_fd(char c, int fd);

size_t	ft_atoi(const char *str);

#endif
