/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:46:36 by apaula-b          #+#    #+#             */
/*   Updated: 2021/07/02 13:42:25 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_with_minus(t_p *print_data, t_c *count, char converted)
{
	int	size_print;

	size_print = ft_strlen(converted);
	if (print_data->width)
	{
	}
}

void	print_int(va_list args, t_p *print_data, t_c *count)
{
	int		print;
	char	converted;

	print = va_arg(args, int);
	converted = ft_itoa(print);
	if (print_data->flag_minus)
		print_with_minus(print_data, count, converted);
	else if (print_data->flag_zero)
		print_with_zero(print_data, count);
	else if (print_data->width)
		print_with_width(print_data, count);
	else if (print_data->precision)
	{
		write(1, " ", 1);
		count->counter += 1;
	}
	free(converted);
}
