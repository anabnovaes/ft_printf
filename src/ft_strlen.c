/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:22:17 by apaula-b          #+#    #+#             */
/*   Updated: 2021/07/01 22:41:14 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
	{
		size++;
	}
	return (size);
}

int	get_size_int(long int value)
{
	int			size;
	long int	check_value;

	size = 1;
	if (value < 0)
		value *= -1;
	check_value = value / 10 ;
	while (check_value >= 1)
	{
		check_value /= 10 ;
		size++;
	}
	return (size);
}
