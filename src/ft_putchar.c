/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:30:47 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/11 21:47:09 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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
