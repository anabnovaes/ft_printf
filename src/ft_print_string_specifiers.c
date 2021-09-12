/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_specifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:17:01 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/12 11:53:12 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_str_with_width(t_p *p_data, t_c *count, char *converted)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(converted);
	if (p_data->err_precision)
		counter = p_data->width;
	else if (p_data->precision && p_data->width > p_data->precision)
		print_str_with_precision(p_data, count, converted);
	else if (p_data->width > size_print)
	{
		while (p_data->width - size_print > counter)
		{
			write(1, " ", 1);
			counter++;
		}
		ft_putstr_fd(converted, count);
	}
	else if (p_data->width == p_data->precision)
		ft_putchar_sized(converted, p_data->width, count);
	else if (p_data->width < size_print)
		ft_putstr_fd(converted, count);
	else
		ft_putchar_sized(converted, p_data->width, count);
	count->length += counter;
}

static size_t	get_number_spaces(t_p *p_data, size_t size_print)
{
	size_t	number_spaces;

	if (!p_data->precision && size_print > p_data->width)
		number_spaces = 0;
	else if (!p_data->precision)
		number_spaces = p_data->width - size_print;
	else if (p_data->precision > size_print)
		number_spaces = p_data->width - size_print;
	else
		number_spaces = p_data->width - p_data->precision;
	return (number_spaces);
}

size_t	print_str_with_minus(t_p *p_data, t_c *count, char *value_to_print)
{
	size_t	size_print;
	size_t	counter;
	size_t	number_spaces;

	counter = 0;
	size_print = ft_strlen(value_to_print);
	if (p_data->width > p_data->precision || p_data->width > size_print)
	{
		if (p_data->precision)
			ft_putchar_sized(value_to_print, p_data->precision, count);
		else
			ft_putstr_fd(value_to_print, count);
		number_spaces = get_number_spaces(p_data, size_print);
		while (number_spaces > counter)
		{
			write(1, " ", 1);
			counter++;
		}
		count->length += counter;
	}
	else
		ft_putstr_fd(value_to_print, count);
	count->length += counter;
	return (1);
}

size_t	print_str_with_precision(t_p *p_data, t_c *count, char *value_to_print)
{
	size_t	size_print;
	size_t	counter;
	size_t	number_spaces;

	counter = 0;
	size_print = ft_strlen(value_to_print);
	if (p_data->width > p_data->precision)
	{
		if (p_data->precision > size_print)
			number_spaces = p_data->width - size_print;
		else
			number_spaces = p_data->width - p_data->precision;
		while (number_spaces > counter)
		{
			write(1, " ", 1);
			counter++;
		}
		count->length += counter;
		ft_putchar_sized(value_to_print, p_data->precision, count);
	}
	else if (p_data->precision > size_print)
		ft_putstr_fd(value_to_print, count);
	else
		ft_putchar_sized(value_to_print, p_data->precision, count);
	return (1);
}
