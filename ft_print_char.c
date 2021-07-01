/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:03:20 by apaula-b          #+#    #+#             */
/*   Updated: 2021/07/01 19:24:26 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_with_minus(char data, t_p *print_data, t_c *count)
{
	write(1, &data, 1);
	if (print_data->width)
	{
		count->length += print_data->width;
		while (print_data->width-- > 1)
			write(1, " ", 1);
	}
	else
		count->length += 1;
}

static void	print_with_width(char data, t_p *print_data, t_c *count)
{
	count->length += print_data->width;
	while (print_data->width-- > 1)
		write(1, " ", 1);
	write(1, &data, 1);
}

void	print_char(va_list args, t_p *print_data, t_c *count)
{
	char	data_to_print;

	data_to_print = va_arg(args, int);
	if (print_data->flag_minus)
	{
		print_with_minus(data_to_print, print_data, count);
	}
	else if (print_data->width)
	{
		print_with_width(data_to_print, print_data, count);
	}
	else
	{
		write(1, &data_to_print, 1);
		count->counter += 1;
	}
}
