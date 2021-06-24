/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:03:20 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/24 11:19:27 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

size_t	print_char(t_params print_data, va_list args)
{
	char	data_to_print;

	data_to_print = va_arg(args, char);
	write(1, &data_to_print, 1);
	return (1);
}
