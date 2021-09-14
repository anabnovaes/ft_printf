/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:43:17 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/12 12:19:35 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	get_flags(const char *data, va_list args, t_p *print_data)
{
	size_t	c_positions;

	c_positions = 0;
	while (ft_isflag(data[c_positions]))
	{
		if (*data == '-')
			print_data->flag_minus = true;
		else if (*data == '0')
			print_data->flag_zero = true;
		else if (*data == '*')
			print_data->width = va_arg(args, size_t);
		else
			return (c_positions);
		c_positions++;
	}
	return (c_positions);
}

int	get_width(const char *data, t_p *print_data)
{
	int		size_int;

	size_int = 0;
	print_data->width = ft_atoi(data);
	size_int = get_size_int(print_data->width);
	return (size_int);
}

size_t	get_precision(const char *data, t_p *print_data, va_list args)
{
	size_t	counter_size;

	counter_size = 0;
	if (data[counter_size] == '*')
	{
		print_data->precision = va_arg(args, size_t);
		return (1);
	}
	print_data->precision = ft_atoi(&data[1]);
	if (data[1] == '0' && !print_data->precision)
	{
		counter_size++;
	}
	else if (data[1] == '0')
		while (data[counter_size + 1] == '0')
			counter_size++;
	if (!print_data->precision)
	{
		print_data->err_precision = true;
		return (counter_size + 1);
	}
	counter_size += get_size_int(print_data->precision) + 1;
	return (counter_size);
}
