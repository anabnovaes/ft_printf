/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:46:36 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/03 00:54:54 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

size_t	print_int(va_list args, t_p *p_data, t_c *count, const char *type)
{
	char	*converted;
	char	*compare_zero;

	converted = NULL;
	compare_zero  = "0";
	converted = convert_int(args, type, p_data);
	if (!converted)
	{
		free(converted);
		return (0);
	}
	if (p_data->flag_minus || p_data->precision || p_data->width)
		print_int_specifier(converted, p_data, count);
	else if(p_data->err_precision && !ft_strncmp(converted,compare_zero, 3))
	{
		free(converted);
		return (0);
	}
	else
		ft_putstr_fd(converted, count);
	free(converted);
	return (1);
}
