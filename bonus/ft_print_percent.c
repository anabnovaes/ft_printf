/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:46:36 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/10 18:29:48 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_p *p_data, t_c *count)
{
	if (p_data->flag_minus || p_data->flag_zero || p_data->width)
		print_specifier("%", p_data, count);
	else
	{
		write(1, "%", 1);
		count->length += 1;
	}
}
