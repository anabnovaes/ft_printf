/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:43:17 by apaula-b          #+#    #+#             */
/*   Updated: 2021/07/01 22:42:13 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	get_flags(const char *data, va_list args, t_p *print_data)
{
	size_t	c_positions;

	c_positions = 0;
	while (!ft_isdigit(data[c_positions]) || data[c_positions] == '0')
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
	char	*width;

	counter_size = 0;
	width = NULL;
	if (data[counter_size] == '*')
	{
		print_data->width = va_arg(args, size_t);
		return (1);
	}
	print_data->width = ft_atoi(data);
	counter_size = get_size_int(print_data->width);
	return (counter_size);
}
