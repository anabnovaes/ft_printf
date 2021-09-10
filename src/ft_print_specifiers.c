/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:44:45 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/10 17:46:10 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_with_minus(t_p *print_data, t_c *count, char *value_to_print)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(value_to_print);
	if (print_data->width > size_print)
	{
		ft_putstr_fd(value_to_print, count);
		while (print_data->width - size_print > counter)
		{
			write(1, " ", 1);
			counter++;
		}
	}
	else if (print_data->width < size_print)
		ft_putchar_sized(value_to_print, print_data->width, count);
	else
		ft_putstr_fd(value_to_print, count);
	count->length += counter + size_print;
}
