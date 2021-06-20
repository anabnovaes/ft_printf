/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:17:12 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/20 12:07:57 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	counter;
	size_t	len;
	int		response[2];

	va_start(args, format);
	len = 0;
	counter = 0;
	while (format[counter])
	{
		if (format[counter] == '%')
		{
			get_data_and_print(format + counter, args, &response);
			counter += response[0];
			len += response[1];
		}
		else
		{
			ft_putchar_fd(format[counter], 1);
			len += 1;
		}
		counter++;
	}
	va_end(args);
	return (len);
}

int	get_data_and_print(char *data, va_list args, int *response)
{
	int			count;
	t_params	*print_data;

	count = 0;
	while (!ft_isdigit(data[count]))
	{
		count += get_flags_and_precision(data[count], args, &print_data);
	}
}

size_t	get_flags_and_precision(char *data, va_list args, t_params *print_data)
{
}
