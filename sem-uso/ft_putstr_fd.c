/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AnaNovaes-MBA <AnaNovaes-MBA@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:42:13 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/19 20:42:07 by AnaNovaes-M      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
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
}
