/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:46:36 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/05 20:54:07 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_with_minus(t_p *print_data, t_c *count, char *converted)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(converted);
	if (print_data->width > size_print)
	{
		ft_putstr_fd(converted, 1, count);
		while (print_data->width - size_print > counter)
		{
			write(1, " ", 1);
			counter++;
		}
	}
	else if (print_data->width < size_print)
		ft_putchar_sized(converted, 1, print_data->width, count);
	else
		ft_putstr_fd(converted, 1, count);
	count->length += counter + size_print;
}

static void	print_with_zero(t_p *print_data, t_c *count, char *converted)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(converted);
	if (print_data->width > size_print)
	{
		while (print_data->width - size_print > counter)
		{
			write(1, "0", 1);
			counter++;
		}
		ft_putstr_fd(converted, 1, count);
	}
	else if (print_data->width < size_print)
		ft_putchar_sized(converted, 1, print_data->width, count);
	else
		ft_putstr_fd(converted, 1, count);
}

static void	print_with_width(t_p *print_data, t_c *count, char *converted)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(converted);
	if (print_data->width < size_print)
		ft_putchar_sized(converted, 1, print_data->width, count);
	else
		ft_putstr_fd(converted, 1, count);
}

size_t	print_int(va_list args, t_p *print_data, t_c *count)
{
	int		print;
	char	*converted;

	converted = NULL;
	print = va_arg(args, int);
	if (!print || print != 0)
		return (0);
	converted = ft_itoa(print);
	if (print_data->flag_minus)
		print_with_minus(print_data, count, converted);
	else if (print_data->flag_zero)
		print_with_zero(print_data, count, converted);
	else if (print_data->width)
		print_with_width(print_data, count, converted);
	else
		ft_putstr_fd(converted, 1, count);
	free(converted);
	return (1);
}
