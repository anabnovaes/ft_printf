/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AnaNovaes-MBA <AnaNovaes-MBA@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:21:58 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/19 20:42:17 by AnaNovaes-M      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] == c)
			return ((char *)s + counter);
		counter++;
	}
	if (s[counter] == c)
		return ((char *)s + counter);
	return (NULL);
}
