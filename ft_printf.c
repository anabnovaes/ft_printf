/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:17:12 by apaula-b          #+#    #+#             */
/*   Updated: 2021/07/02 13:41:25 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_type(const char *data, va_list args, t_p *print, t_c *count)
{
	if (*data == 'c')
		print_char(args, print, count);
	else if (*data == '%')
		print_percent(print, count);
	//else if (*data == 'd' || *data == 'i')
	//	print_int(args, print, count);
	else
		count->counter += 1;
}

void	get_data(const char *data, va_list args, t_c *c)
{
	t_p	print_data;

	start_struct(&print_data);
	while (ft_isflag(data[c->counter]))
		c->counter += get_flags(data + c->counter, args, &print_data);
	while (ft_isdigit(data[c->counter]))
		c->counter += get_width(data + c->counter, &print_data);
	if (data[c->counter] == '.')
		c->counter += get_precision(data + c->counter, &print_data, args);
	if (ft_isalpha(data[c->counter]) || data[c->counter] == '%')
		get_type(data + c->counter, args, &print_data, c);
	else if (data[c->counter] == ' ' || !data[c->counter])
		c->counter += 1;
	else
	{
		c->counter += 1;
		get_data(data, args, c);
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

/* int main(void)
{
	ft_printf("%c%c%c", 'a', 'b', 'c');
}
*/