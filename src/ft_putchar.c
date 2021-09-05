/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:30:47 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/05 20:38:02 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd, t_c *count)
{
	size_t	counter;

	count = 0;
	if (s == NULL)
		return ;
	while (s[counter])
	{
		write(fd, &s[counter], 1);
		count++;
	}
	count->length += ft_strlen(s);
}

void	ft_putchar_sized(char *s, int fd, size_t size, t_c *count)
{
	size_t	counter;

	counter = 0;
	while (size > counter)
	{
		write(fd, &s[counter], 1);
		counter++;
	}
	count->length += ft_strlen(size);
}

void	print_null(t_c *count)
{
	write(1, "(null)", 6);
	count->length += 6;
}
