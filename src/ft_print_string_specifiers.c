/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_specifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:17:01 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/11 23:18:07 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_str_with_width(t_p *print_data, t_c *count, char *converted)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(converted);
	if (print_data->width > size_print)
	{
		while (print_data->width - size_print > counter)
		{
			write(1, " ", 1);
			counter++;
		}
		ft_putstr_fd(converted, count);
	}
	else if (print_data->width < size_print)
		ft_putstr_fd(converted, count);
	else
		ft_putchar_sized(converted, print_data->width, count);
	count->length += counter;
}

size_t	print_str_with_minus(t_p *print_data, t_c *count, char *value_to_print)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(value_to_print);
	if (print_data->err_precision)
		return (0);
	else if (print_data->width > size_print)
	{
		ft_putstr_fd(value_to_print, count);
		while (print_data->width - size_print > counter)
		{
			write(1, " ", 1);
			counter++;
		}
	}
	else
		ft_putstr_fd(value_to_print, count);
	count->length += counter;
	return (1);
}
