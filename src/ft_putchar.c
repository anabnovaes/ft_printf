/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:30:47 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/04 09:06:50 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr_fd(char *s, t_c *count)
{
	size_t	counter;

	counter = 0;
	if (s == NULL)
		return ;
	while (s[counter])
	{
		write(1, &s[counter], 1);
		counter++;
	}
	count->length += counter;
}

void	ft_putchar_sized(char *s, size_t size, t_c *count)
{
	size_t	counter;

	counter = 0;
	while (size > counter)
	{
		write(1, &s[counter], 1);
		counter++;
	}
	count->length += counter;
}

void	ft_putspaces(size_t value, t_c *count)
{
	size_t	counter;

	counter = 0;
	while (value > counter)
	{
		write(1, " ", 1);
		counter++;
	}
	count->length += counter;
}

void	ft_putstr(char string, t_c *count)
{
	write(1, &string, 1);
	count->length += 1;
}

void	ft_putzeros(size_t value, t_c *count)
{
	size_t	counter;

	counter = 0;
	while (value > counter)
	{
		write(1, "0", 1);
		counter++;
	}
	count->length += counter;
}
