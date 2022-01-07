/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:53:10 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/05 18:20:14 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_pointer(va_list args, t_c *count)
{
	unsigned long	data_to_print;
	char			*converted;

	data_to_print = va_arg(args, unsigned long);
	if (!data_to_print)
	{
		ft_putstr_fd("0x0", count);
		return (0);
	}
	converted = ft_utoa_long(data_to_print);
	if (!converted)
	{
		free(converted);
		return (0);
	}
	else
		ft_putstr_fd(converted, count);
	free(converted);
	return (1);
}
