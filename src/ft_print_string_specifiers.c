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

void	print_str_with_width(t_p *print_data, t_c *count, char *converted)
{
	size_t	size_print;

	size_print = ft_strlen(converted);
	if (print_data->err_precision && print_data->width)
		ft_putspaces(print_data->width, count);
	else if (print_data->err_precision)
		count->length = print_data->width;
	else if (print_data->precision && print_data->width > print_data->precision)
		print_str_with_precision(print_data, count, converted);
	else if (print_data->width > size_print)
	{
		ft_putspaces(print_data->width - size_print, count);
		ft_putstr_fd(converted, count);
	}
	else if (print_data->width == print_data->precision)
		ft_putchar_sized(converted, print_data->width, count);
	else if (print_data->width < size_print)
		ft_putstr_fd(converted, count);
	else
		ft_putchar_sized(converted, print_data->width, count);
}

size_t	get_number_spaces(t_p *print_data, size_t size_print)
{
	size_t	number_spaces;

	if (!print_data->precision && size_print > print_data->width)
		number_spaces = 0;
	else if (!print_data->precision)
		number_spaces = print_data->width - size_print;
	else if (print_data->precision > size_print)
		number_spaces = print_data->width - size_print;
	else
		number_spaces = print_data->width - print_data->precision;
	return (number_spaces);
}

size_t	print_str_with_minus(t_p *p_data, t_c *count, char *print_value)
{
	size_t	size_c;
	size_t	counter;
	size_t	number_spaces;

	counter = 0;
	size_c = ft_strlen(print_value);
	if (p_data->err_precision && !p_data->width)
		count->length += 0;
	else if (p_data->err_precision)
		count->length = p_data->width;
	 else if (p_data->width > p_data->precision || p_data->precision > size_c)
	{
		if (p_data->precision > size_c)
			ft_putchar_sized(print_value, size_c, count);
		else if (p_data->precision)
			ft_putchar_sized(print_value, p_data->precision, count);
		else
			ft_putstr_fd(print_value, count);
		number_spaces = get_number_spaces(p_data, size_c);
		ft_putspaces(number_spaces, count);
	}
	else
		ft_putstr_fd(print_value, count);
	count->length += counter;
	return (1);
}

size_t	print_str_with_precision(t_p *print_data, t_c *count, char *print_value)
{
	size_t	size_print;
	size_t	number_spaces;

	size_print = ft_strlen(print_value);
	if (print_data->width > print_data->precision)
	{
		if (print_data->precision > size_print)
			number_spaces = print_data->width - size_print;
		else
			number_spaces = print_data->width - print_data->precision;
		ft_putspaces(number_spaces, count);
		ft_putchar_sized(print_value, print_data->precision, count);
	}
	else if (print_data->precision > size_print)
		ft_putstr_fd(print_value, count);
	else
		ft_putchar_sized(print_value, print_data->precision, count);
	return (1);
}
