/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:22:35 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/10 14:08:22 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_toupper(char *c)
{
	int	counter;

	counter = 0;
	while (c[counter])
	{
		if (c[counter] >= 'a' && c[counter] <= 'z')
			c[counter] -= 32;
		counter++;
	}
	return (c);
}
