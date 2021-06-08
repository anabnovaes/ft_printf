/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:17:12 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/06 16:18:58 by apaula-b         ###   ########.fr       */
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
	while (format[counter])
	{
		if (format[counter] == "%" && format[counter + 1] == "%")
		{
			len += ft_putchar_fd(format[counter, 1]);
			counter ++;
		}
		else if (format[counter] == "%")
		{
			len += get_flags_and_precision(format[counter], args);
		}
		else
			len += ft_putchar_fd(format[counter, 1]);
		counter++;
	}
	return (len);
}
