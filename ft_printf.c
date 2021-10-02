/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:17:12 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/11 22:05:15 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_type(const char *data, va_list args, t_c *counters)
{
	if (*data == 'c')
		print_char(args, counters);
	else if (*data == '%')
		print_percent(counters);
	else if (*data == 's')
		print_string(args, counters);
	else if (*data == 'd' || *data == 'i' || *data == 'u')
		print_int(args, counters, data);
	else if (*data == 'x' || *data == 'X' )
		print_hexa(args, counters, data);
	else if (*data == 'p')
		print_pointer(args, counters);
	else
	{
		print_percent(counters);
		counters->counter += 1;
	}
}


int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_c			counters;

	va_start(args, format);
	start_counters(&counters);
	while (format[counters.counter])
	{
		if (format[counters.counter] == '%')
		{
			counters.counter++;
			get_type(&format[counters.counter], args, &counters);
		}
		else
		{
			ft_putchar_fd(format[counters.counter], 1);
			counters.length++;
		}
		counters.counter++;
	}
	va_end(args);
	return (counters.length);
}

