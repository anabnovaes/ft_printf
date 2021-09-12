/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:30:28 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/11 23:46:42 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

size_t	print_string(va_list args, t_p *print_data, t_c *count)
{
	char	*data_to_print;
	size_t	size_print;

	data_to_print = va_arg(args, char *);
	if (!data_to_print)
		data_to_print = "(null)";
	size_print = ft_strlen(data_to_print);
	if (print_data->flag_minus)
		print_str_with_minus(print_data, count, data_to_print);
	else if (print_data->width)
		print_str_with_width(print_data, count, data_to_print);
	else if (print_data->precision)
		print_str_with_precision(print_data, count, data_to_print);
	else if (print_data->err_precision)
	{
		count->length += 2;
		return (1);
	}
	else
		ft_putstr_fd(data_to_print, count);
	return (1);
}

void	print_char(va_list args, t_p *print_data, t_c *count)
{
	char	data_to_print;

	data_to_print = va_arg(args, int);
	if (print_data->flag_minus && print_data->width)
		print_with_minus(print_data, count, &data_to_print);
	else if (print_data->width)
		print_with_width(print_data, count, &data_to_print);
	else
	{
		write(1, &data_to_print, 1);
		count->length += 1;
	}
}

int	main(void)
{
	ft_printf("\n ft_prinf:|%.3s|", "hello");
	printf("\n size ft_prinf: |%d|", ft_printf("%.3s", "hello"));
}
