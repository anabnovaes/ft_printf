/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:17:31 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/10 17:19:05 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*convert_int(va_list args, const char *type)
{
	int				print;
	unsigned int	print_positive;
	char			*converted;

	converted = NULL;
	if (*type == 'u')
	{
		print_positive = va_arg(args, unsigned int);
		converted = ft_itoa_unsigned(print_positive);
	}
	else
	{
		print = va_arg(args, int);
		converted = ft_itoa(print);
	}
	return (converted);
}

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
