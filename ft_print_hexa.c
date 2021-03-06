/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:31:12 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/05 18:22:48 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_hexa(va_list args, t_c *count, const char *data)
{
	unsigned int	print;
	char			*converted;

	print = 0;
	converted = NULL;
	print = va_arg(args, unsigned int);
	converted = ft_utoa(print);
	if (*data == 'X')
		ft_toupper(converted);
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
