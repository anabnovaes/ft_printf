/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:44:45 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/11 22:12:45 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

size_t	print_with_minus(t_p *print_data, t_c *count, char *value_to_print)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(value_to_print);
	if (print_data->precision)
		return (0);
	else if (print_data->width > size_print)
	{
		ft_putstr_fd(value_to_print, count);
		while (print_data->width - size_print > counter)
		{
			write(1, " ", 1);
			counter++;
		}
	}
	else if (print_data->width && print_data->width < size_print)
		ft_putchar_sized(value_to_print, print_data->width, count);
	else
		ft_putstr_fd(value_to_print, count);
	count->length += counter;
	return (1);
}

void	print_with_width(t_p *print_data, t_c *count, char *converted)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(converted);
	while (print_data->width - size_print > counter)
	{
		write(1, " ", 1);
		counter++;
	}
	ft_putstr_fd(converted, count);
	count->length += counter;
}

void	print_with_flag_zero(t_p *print_data, t_c *count, char *converted)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(converted);
	if (print_data->width)
	{
		while (print_data->width - size_print > counter)
		{
			write(1, "0", 1);
			counter++;
		}
		ft_putstr_fd(converted, count);
	}
	else
		ft_putstr_fd(converted, count);
	count->length += counter;
}

void	print_specifier(char *converted, t_p *print_data, t_c *count)
{
	if (print_data->flag_minus)
		print_with_minus(print_data, count, converted);
	else if (print_data->flag_zero)
		print_with_flag_zero(print_data, count, converted);
	else if (print_data->width)
		print_with_width(print_data, count, converted);
}
