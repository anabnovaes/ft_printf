/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:30:28 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/10 18:13:32 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_string(va_list args, t_p *print_data, t_c *count)
{
	char	*data_to_print;
	size_t	size_print;

	data_to_print = va_arg(args, char *);
	if (!data_to_print)
	{
		print_null(count);
		return (0);
	}
	size_print = ft_strlen(data_to_print);
	if (print_data->flag_minus)
		print_with_minus(print_data, count, data_to_print);
	else if (print_data->width)
		print_with_width(print_data, count, data_to_print);
	else
		ft_putstr_fd(data_to_print, count);
	return (1);
}

void	print_char(va_list args, t_p *print_data, t_c *count)
{
	char	data_to_print;

	data_to_print = va_arg(args, int);
	if (print_data->flag_minus)
		print_with_minus(print_data, count, &data_to_print);
	else if (print_data->width)
		print_with_width(print_data, count, &data_to_print);
	else
	{
		write(1, &data_to_print, 1);
		count->length += 1;
	}
}
