/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:03:20 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/28 21:52:16 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args)
{
	char	data_to_print;

	data_to_print = va_arg(args, int);
	write(1, &data_to_print, 1);
	return (1);
}
