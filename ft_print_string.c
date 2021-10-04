/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:30:28 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/03 20:23:29 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_string(va_list args, t_p *print_data, t_c *count)
{
	char	*data_to_print;

	data_to_print = va_arg(args, char *);
	if (!data_to_print)
		data_to_print = "(null)";
	if (print_data->flag_minus)
		print_str_with_minus(print_data, count, data_to_print);
	else if (print_data->width)
		print_str_with_width(print_data, count, data_to_print);
	else if ((print_data->err_precision && !print_data->width)
		|| print_data->err_precision )
		return (1);
	else if (print_data->precision)
		print_str_with_precision(print_data, count, data_to_print);
	else
		ft_putstr_fd(data_to_print, count);
	return (1);
}

size_t	print_char(va_list args, t_p *print_data, t_c *count)
{
	char	data_to_print;

	data_to_print = va_arg(args, int);
	if ((print_data->flag_minus && print_data->width) || print_data->flag_minus)
		print_char_with_minus(print_data, count, data_to_print);
	else if (print_data->width)
		print_char_with_width(print_data, count, data_to_print);
	else
	{
		write(1, &data_to_print, 1);
		count->length += 1;
	}
	return (1);
}
