/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:45:57 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/20 13:26:26 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	count;

	count = 0;
	if (s == NULL)
	{
		return ;
	}
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
	write(fd, "\n", 1);
	return (count);
}
