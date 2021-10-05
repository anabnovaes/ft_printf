/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:30:47 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/05 18:15:00 by apaula-b         ###   ########.fr       */
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

void	ft_putstr(char string, t_c *count)
{
	write(1, &string, 1);
	count->length += 1;
}
