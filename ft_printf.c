/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:17:12 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/28 22:08:35 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	start_struct(t_params **print_data)
{
	print_data[0]->flag_minus = false;
	print_data[0]->flag_zero = false;
	print_data[0]->width = 0;
	print_data[0]->precision = 0;
}

int	get_type_and_print(const char *data, va_list args)
{
	int	size_print;

	size_print = 0;
	//if (*data == 's')
	//	size_print = print_string(print_data, args);
	if (*data == 'c')
		size_print = print_char(args);
	/*if (*data == 'd' || *data == 'i')
		size_print = print_int(print_data, args);
	if (*data == 'x' || *data == 'X')
		size_print = print_hexa(print_data, args);
	if (*data == '%')
		size_print = print_percent(print_data, args);
	if (*data == 'u')
		size_print = print_unsigned(print_data, args);
	if (*data == 'p')
		size_print = print_pointer(print_data, args);
	return (size_print); */
	return (size_print);
}

int	get_data_and_print(const char *data, va_list args, int *response)
{
	int			count;
	t_params	*print_data;

	count = 1;
	start_struct(&print_data);
	while (ft_isflag(data + count))
		count += get_flags(data + count, args, &print_data);
	while (ft_isdigit(data[count]))
		count += get_width(data + count, &print_data);
	if (data[count] == '.')
		count += get_precision(data + count, &print_data, args);
	if (ft_isalpha(data[count]) || data[count] == '%')
	{
		*response = get_type_and_print(data + count, args);
	}
	return (count + 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		len;
	int		*response;

	va_start(args, format);
	len = 0;
	counter = 0;
	response = 0;
	while (format[counter])
	{
		if (format[counter] == '%')
		{
			counter += get_data_and_print(format + counter, args,response);
			len += *response;
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

int	main(void)
{
	ft_printf("oi %c \n HELO", 'a');
}
