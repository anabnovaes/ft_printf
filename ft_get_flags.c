/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:43:17 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/20 19:19:01 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_flags(char *data, va_list args, t_params *print_data)
{
	size_t	c_positions;

	c_positions = 0;
	while (!ft_isdigit(data[c_positions]) || data[c_positions] == '0')
	{
		if (*data == '-')
			print_data->flag_minus = true;
		else if (*data == '0')
			print_data->flag_zero = true;
		else if (!print_data->width && *data == '*')
			print_data->width = va_arg(args, size_t);
		else
			return (c_positions);
		c_positions++;
	}
	return (c_positions);
}

size_t	get_width(char *data, t_params *print_data)
{
	size_t	counter_size;
	char	*width;

	counter_size = 0;
	width = NULL;
	while (ft_isdigit(data[counter_size]))
	{
		width[counter_size] = data[counter_size];
		counter_size++;
	}
	print_data->width = ft_atoi(width);
	return (counter_size);
}

size_t	get_precision(char *data, t_params *print_data, va_list args)
{
	size_t	counter_size;
	char	*width;

	counter_size = 0;
	width = NULL;
	if (data[counter_size] == '*')
	{
		print_data->width = va_arg(args, size_t);
		return (1);
	}
	while (ft_isdigit(data[counter_size]))
	{
		width[counter_size] = data[counter_size];
		counter_size++;
	}
	print_data->width = ft_atoi(width);
	return (counter_size);
}
