/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AnaNovaes-MBA <AnaNovaes-MBA@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:22:13 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/19 20:42:47 by AnaNovaes-M      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	counter;

	counter = 0;
	if (len == 0)
	{
		return (ft_strlen((char *)src));
	}
	if (dst == NULL || src == NULL)
	{
		return (0);
	}
	while (counter < len - 1 && src[counter])
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (ft_strlen((char *)src));
}
