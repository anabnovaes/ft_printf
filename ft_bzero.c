/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:18:58 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/26 14:21:09 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;
	char	*final_value;

	counter = 0;
	final_value = (char *)s;
	while (counter < n)
	{
		final_value[counter] = '\0';
		counter++;
	}
}
