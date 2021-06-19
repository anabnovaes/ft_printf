/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AnaNovaes-MBA <AnaNovaes-MBA@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:45:57 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/19 20:41:45 by AnaNovaes-M      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putendl_fd(char *s, int fd)
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
}
