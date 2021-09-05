/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:46:36 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/05 19:32:47 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_with_minus(t_p *print_data, t_c *count)
{
	write(1, "%", 1);
	if (print_data->width)
	{
		count->length += print_data->width;
		while (print_data->width-- > 1)
			write(1, " ", 1);
	}
	else
		count->length += 1;
}

static void	print_with_width(t_p *print_data, t_c *count)
{
	count->length += print_data->width;
	while (print_data->width-- > 1)
		write(1, " ", 1);
	write(1, "%", 1);
}

static void	print_with_zero(t_p *print_data, t_c *count)
{
	if (print_data->width)
	{
		count->length += print_data->width;
		while (print_data->width-- > 1)
			write(1, "0", 1);
	}
	else
		count->length += 1;
	write(1, "%", 1);
}

void	print_percent(t_p *print_data, t_c *count)
{
	if (print_data->flag_minus)
		print_with_minus(print_data, count);
	else if (print_data->flag_zero)
		print_with_zero(print_data, count);
	else if (print_data->width)
		print_with_width(print_data, count);
	else
	{
		write(1, "%", 1);
		count->length += 1;
	}
}
