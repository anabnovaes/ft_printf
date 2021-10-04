/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_specifiers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 23:10:24 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/04 09:12:03 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_up_width(t_p *p_data, t_c *count, char *print, size_t size)
{
	if (p_data->negative_value)
		ft_putspaces(p_data->width - p_data->precision - 1, count);
	else
		ft_putspaces(p_data->width - p_data->precision, count);
	if (p_data->precision > size)
		print_with_zero(print, count, p_data, size);
	else
		ft_putchar_sized(print, p_data->precision, count);
}

void	print_int_specifier(char *converted, t_p *print_data, t_c *count)
{
	if (print_data->flag_minus)
		print_int_with_minus(print_data, count, converted);
	else if (print_data->precision)
		print_int_with_prec(print_data, count, converted);
	else if (print_data->width)
		print_int_with_width(print_data, count, converted);
}

void	print_err_precision(t_p *p_data, t_c *count, char *converted)
{
	size_t	size_converted;
	size_t	number_spaces;
	char	*compare_zero;

	size_converted = ft_strlen(converted);
	compare_zero = "0";
	if (!p_data->width)
		count->length += 0;
	else if (!ft_strncmp(converted, compare_zero, 3) && p_data->width)
		ft_putspaces(p_data->width, count);
	else if (p_data->width > size_converted)
	{
		ft_putstr_fd(converted, count);
		number_spaces = p_data->width - size_converted;
		ft_putspaces(number_spaces, count);
	}
	else if (p_data->err_precision && p_data->width)
		ft_putstr_fd(converted, count);
}
