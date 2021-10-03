/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_specifiers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 23:10:24 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/02 23:51:21 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void print_upper_width(t_p *p_data, t_c *count, char *print, size_t size)
{
	if (p_data->negative_value)
		ft_putspaces(p_data->width - p_data->precision - 1, count);
	else
		ft_putspaces(p_data->width - p_data->precision, count);
	if(p_data->precision > size)
		print_with_zero(print, count, p_data, size);
	else
	ft_putchar_sized(print, p_data->precision, count);
}

void print_int_specifier(char *converted, t_p *print_data, t_c *count)
{
	if (print_data->flag_minus)
		print_int_with_minus(print_data, count, converted);
	else if (print_data->precision)
		print_int_with_precision(print_data, count, converted);
	else if (print_data->width)
		print_int_with_width(print_data, count, converted);
}
