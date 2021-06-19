/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AnaNovaes-MBA <AnaNovaes-MBA@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:17:12 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/19 20:24:40 by AnaNovaes-M      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	counter;
	size_t	len;

	va_start(args, format);
	len = 0;
	counter = 0;
	while (*format)
	{
		if (format[counter] == "%")
		{
			len += get_data_and_print(format[counter], args);
		}
		else
			len += ft_putchar_fd(format[counter, 1]);
	}
	va_end(args);
	return (len);
}
