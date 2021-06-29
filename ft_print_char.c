/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:03:20 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/29 18:48:10 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list args, t_params *print_data)
{
	char	data_to_print;

	data_to_print = va_arg(args, int);
	write(1, &data_to_print, 1);
	print_data->size_printed += 1;
}
