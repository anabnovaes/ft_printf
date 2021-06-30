/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:03:20 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/29 21:15:11 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list args, t_p *print_data, t_c *count)
{
	char	data_to_print;

	data_to_print = va_arg(args, int);
	if (print_data->flag_minus)
	{
		write(1, &data_to_print, 1);
		if (print_data->width)
		{
			count->length += print_data->width;
			while (print_data->width-- > 1)
				write(1, " ", 1);
		}
		else
			count->length += 1;
	}
	else if (print_data->width)
	{
		count->length += print_data->width;
		while (print_data->width-- > 1)
			write(1, " ", 1);
		write(1, &data_to_print, 1);
	}
	else
	{
		write(1, &data_to_print, 1);
		count->counter += 1;
	}
}
