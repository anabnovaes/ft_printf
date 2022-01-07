/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:30:28 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/05 18:20:05 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_string(va_list args, t_c *count)
{
	char	*data_to_print;

	data_to_print = va_arg(args, char *);
	if (!data_to_print)
		data_to_print = "(null)";
	ft_putstr_fd(data_to_print, count);
	return (1);
}

size_t	print_char(va_list args, t_c *count)
{
	char	data_to_print;

	data_to_print = va_arg(args, int);
	write(1, &data_to_print, 1);
	count->length += 1;
	return (1);
}
