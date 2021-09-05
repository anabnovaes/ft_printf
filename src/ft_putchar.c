/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:30:47 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/05 20:20:23 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return ;
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
}

void	ft_putchar_sized(char *s, int fd, size_t size)
{
	size_t	counter;

	counter = 0;
	while (size > counter)
	{
		write(fd, &s[counter], 1);
		counter++;
	}
}

void	print_null(t_c *count)
{
	write(1, "(null)", 6);
	count->length += 6;
}
