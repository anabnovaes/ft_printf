/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:46:36 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/10 18:30:23 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_int(va_list args, t_p *p_data, t_c *count, const char *type)
{
	char	*converted;

	converted = NULL;
	converted = convert_int(args, type);
	if (!converted)
	{
		free(converted);
		return (0);
	}
	else if (p_data->flag_minus || p_data->flag_zero || p_data->width)
		print_specifier(converted, p_data, count);
	else
		ft_putstr_fd(converted, count);
	free(converted);
	return (1);
}