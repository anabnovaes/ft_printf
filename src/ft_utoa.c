/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:07:45 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/10 16:52:42 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	check_size(long int value)
{
	int			size;
	long int	check_value;

	size = 1;
	if (value < 0)
		value *= -1;
	check_value = value / 16 ;
	while (check_value >= 1)
	{
		check_value /= 16 ;
		size++;
	}
	return (size);
}

static char	*convert_value(long int value, int size, char *string)
{
	int			last_value;
	int			counter;

	counter = 1;
	while (counter <= size)
	{
		last_value = value % 16;
		value /= 16;
		if (last_value < 10)
			string[size - counter] = (last_value) + '0';
		else
			string[size - counter] = (last_value) + 87;
		counter++;
	}
	string[size] = '\0';
	return (string);
}

char	*ft_utoa(unsigned int integer)
{
	char	*value;
	int		size;
	int		spaces;

	spaces = 0;
	size = check_size(integer);
	if (integer < 0)
		spaces = 1;
	value = ft_calloc(sizeof(char), size + 1 + spaces);
	if (!value)
		return (NULL);
	value = convert_value(integer, size, value);
	return (value);
}
