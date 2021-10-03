/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 23:46:15 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/02 23:51:03 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_int_with_minus(t_p *p_data, t_c *count, char *converted)
{
	size_t	size_c;
	size_t	number_spaces;

	size_c = ft_strlen(converted);
	if (p_data->err_precision && !p_data->width)
		count->length += 0;
	else if (p_data->err_precision)
		count->length = p_data->width;
	 else if (p_data->width > p_data->precision || p_data->precision > size_c)
	{
		if (p_data->precision > size_c)
			ft_putchar_sized(converted, size_c, count);
		else if (p_data->precision)
			ft_putchar_sized(converted, p_data->precision, count);
		else
			ft_putstr_fd(converted, count);
		number_spaces = get_number_spaces(p_data, size_c);
		ft_putspaces(number_spaces, count);
	}
	else
		ft_putstr_fd(converted, count);
}

void	print_int_with_width(t_p *print_data, t_c *count, char *converted)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(converted);
	if (print_data->width > size_print && print_data->flag_zero)
	{
		ft_putzeros(print_data->width - size_print, count);
		ft_putstr_fd(converted, count);
	}
	else if (print_data->width > size_print)
	{
		ft_putspaces(print_data->width - size_print, count);
		ft_putstr_fd(converted, count);
	}
	else
		ft_putstr_fd(converted, count);
	count->length += counter;
}

void	print_with_zero(char *p_value, t_c *count,t_p *print_data, size_t size)
{
	if (p_value[0] == '-')
	{
		ft_putchar_sized(&p_value[0], 1, count);
		ft_putzeros(print_data->precision - size + 1, count);
		ft_putchar_sized(&p_value[1], size - 1, count);
	}
	else
	{
		ft_putzeros(print_data->precision - size, count);
		ft_putchar_sized(p_value, size, count);
	}
}

size_t	print_int_with_precision(t_p *print_data, t_c *count, char *print_value)
{
	size_t	size_print;

	size_print = ft_strlen(print_value);
	if (print_data->width > print_data->precision)
		print_upper_width(print_data,count, print_value, size_print);
	else if (print_data->precision > size_print)
		print_with_zero(print_value, count,print_data, size_print);
	else if (print_data->precision == size_print && *print_value == '-')
	{
		ft_putchar_sized(&print_value[0], 1, count);
		ft_putzeros(print_data->precision - size_print + 1, count);
		ft_putchar_sized(&print_value[1], size_print - 1, count);
	}
	else
		ft_putchar_sized(print_value, size_print, count);
	return (1);
}
