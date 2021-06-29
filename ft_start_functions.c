/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:58:46 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/29 20:13:37 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	start_struct(t_p **print_data)
{
	print_data[0]->flag_minus = false;
	print_data[0]->flag_zero = false;
	print_data[0]->width = 0;
	print_data[0]->precision = 0;
	print_data[0]->size_printed = 0;
}

void	start_counters(t_c *counters)
{
	counters->counter = 0;
	counters->length = 0;
}
