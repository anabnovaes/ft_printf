/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:58:46 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/11 23:08:13 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	start_struct(t_p *print_data)
{
	print_data->flag_minus = false;
	print_data->flag_zero = false;
	print_data->width = 0;
	print_data->precision = false;
	print_data->err_precision = false;
}

void	start_counters(t_c *counters)
{
	counters->counter = 0;
	counters->length = 0;
}
