/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:17:12 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/29 20:48:47 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	get_type(const char *data, va_list args, t_p *print, t_c *count)
{
	int	size_print;

	size_print = 0;
	//if (*data == 's')
	//	size_print = print_string(print_data, args);
	if (*data == 'c')
		print_char(args, print, count);
	/*if (*data == 'd' || *data == 'i')
		size_print = print_int(print_data, args);
	if (*data == 'x' || *data == 'X')
		size_print = print_hexa(print_data, args);
	if (*data == '%')
		size_print = print_percent(print_data, args);
	if (*data == 'u')
		size_print = print_unsigned(print_data, args);
	if (*data == 'p')
		size_print = print_pointer(print_data, args);  */
}

void	get_data(const char *data, va_list args, t_c *c)
{
	t_p	print_data;

	start_struct(&print_data);
	while (ft_isflag(data + c->counter))
		c->counter += get_flags(data + c->counter, args, &print_data);
	while (ft_isdigit(data[c->counter]))
		c->counter += get_width(data + c->counter, &print_data);
	if (data[c->counter] == '.')
		c->counter += get_precision(data + c->counter, &print_data, args);
	if (ft_isalpha(data[c->counter]) || data[c->counter] == '%')
		get_type(data + c->counter, args, &print_data, c);
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
			get_data(format, args, &counters);
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

int	main(void)
{
	ft_printf("oi %c teste|", 'a');
}
