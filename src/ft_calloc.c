/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:24:15 by apaula-b          #+#    #+#             */
/*   Updated: 2021/07/01 22:40:08 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	else
	{
		ft_bzero(pointer, count * size);
		return (pointer);
	}
}
