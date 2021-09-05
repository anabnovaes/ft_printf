/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:30:28 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/05 20:23:11 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_with_minus(char *data_to_print, t_p *print_data, t_c *count)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(data_to_print);
	if (print_data->width > size_print)
	{
		ft_putstr_fd(data_to_print, 1);
		while (print_data->width - size_print > counter)
		{
			write(1, " ", 1);
			counter++;
		}
	}
	else if (print_data->width < size_print)
		ft_putchar_sized(data_to_print, 1, print_data->width);
	else
		ft_putstr_fd(data_to_print, 1);
	count->length += counter + size_print;
}

static void	print_with_width(char *data_to_print, t_p *print_data, t_c *count)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(data_to_print);
	if (print_data->width < size_print)
		ft_putchar_sized(data_to_print, 1, print_data->width);
	else
		ft_putstr_fd(data_to_print, 1);
	count->length += counter + size_print;
}

size_t	print_string(va_list args, t_p *print_data, t_c *count)
{
	char	*data_to_print;
	size_t	size_print;

	data_to_print = va_arg(args, char *);
	if (!data_to_print)
	{
		print_null(count);
		return (0);
	}
	size_print = ft_strlen(data_to_print);
	if (print_data->flag_minus)
		print_with_minus(data_to_print, print_data, count);
	else if (print_data->width)
		print_with_width(data_to_print, print_data, count);
	else
	{
		ft_putstr_fd(data_to_print, 1);
		count->length += size_print;
	}
	return (1);
}
