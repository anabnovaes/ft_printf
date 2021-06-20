/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:17:12 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/20 18:51:29 by apaula-b         ###   ########.fr       */
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
			get_data_and_print(format + counter + 1, args, &response);
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

void	get_data_and_print(char *data, va_list args, int *response)
{
	size_t		count;
	t_params	*print_data;

	count = 0;
	start_struct(&print_data);
	while (!ft_isdigit(data[count]) || data[count] == '0')
		count += get_flags(data[count], args, &print_data);
	while (ft_isdigit(data[count]))
		count += get_width(data[count], &print_data);
	if (data[count] == '.')
		count += get_precision(data[count], &print_data, args);
	if (ft_isalpha(data[count]) || data[count] == '%')
	{
		response[1] = print_value(data[count], &print_data, args);
	}
	response[0] = count;
}

void	start_struct(t_params *print_data)
{
	print_data->flag_minus = false;
	print_data->flag_zero = false;
	print_data->width = 0;
	print_data->precision = 0;
}
