/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:53:10 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/10 14:53:07 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_pointer(va_list args, t_p *print_data, t_c *count)
{
	unsigned long int	data_to_print;

	data_to_print = va_arg(args, unsigned long int);
	if (!data_to_print)
	{
		print_null(count);
		return (0);
	}
	print_data->width += 1;
	count->length += 1;
	return ((size_t)data_to_print);
}
