/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_specifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:17:01 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/12 11:53:12 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_char_with_width(t_p *p_data, t_c *count, char converted)
{
	if (p_data->flag_minus)
		print_char_with_minus(p_data, count, converted);
	else if (p_data->width > 1)
	{
		ft_putspaces(p_data->width - 1, count);
		ft_putstr(converted, count);
	}
	else
		ft_putstr(converted, count);
}

size_t	print_char_with_minus(t_p *p_data, t_c *count, char converted)
{
	size_t	number_spaces;

	 if (p_data->err_precision)
		count->length = p_data->width;
	 else if (p_data->width > 1)
	{
		ft_putstr(converted, count);
		number_spaces = p_data->width - 1;
		ft_putspaces(number_spaces, count);
	}
	else
		ft_putstr(converted, count);
	return (1);
}
