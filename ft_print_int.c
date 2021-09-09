/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:46:36 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/09 20:39:00 by apaula-b         ###   ########.fr       */
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
		ft_putstr_fd(converted, count);
		while (print_data->width - size_print > counter)
		{
			write(1, " ", 1);
			counter++;
		}
	}
	else if (print_data->width < size_print)
		ft_putchar_sized(converted, print_data->width, count);
	else
		ft_putstr_fd(converted, count);
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
		ft_putstr_fd(converted, count);
	}
	else if (print_data->width < size_print)
		ft_putchar_sized(converted, print_data->width, count);
	else
		ft_putstr_fd(converted, count);
}

static void	print_with_width(t_p *print_data, t_c *count, char *converted)
{
	size_t	size_print;
	size_t	counter;

	counter = 0;
	size_print = ft_strlen(converted);
	if (print_data->width < size_print)
		ft_putchar_sized(converted, print_data->width, count);
	else
		ft_putstr_fd(converted, count);
}

static void	print_specifier(char *converted, t_p *print_data, t_c *count)
{
	if (print_data->flag_minus)
		print_with_minus(print_data, count, converted);
	else if (print_data->flag_zero)
		print_with_zero(print_data, count, converted);
	else if (print_data->width)
		print_with_width(print_data, count, converted);
}

size_t	print_int(va_list args, t_p *p_data, t_c *count)
{
	int			print;
	char		*converted;

	print = 0;
	converted = NULL;
	print = va_arg(args, int);
	converted = ft_itoa(print);
	if (!converted)
	{
		free(converted);
		return (0);
	}
	else if (p_data->flag_minus || p_data->flag_zero || p_data->width)
		print_specifier(converted, p_data, count);
	else
		ft_putstr_fd(converted, count);
	free(converted);
	return (1);
}
