/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AnaNovaes-MBA <AnaNovaes-MBA@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:18:58 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/19 20:40:28 by AnaNovaes-M      ###   ########.fr       */
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
