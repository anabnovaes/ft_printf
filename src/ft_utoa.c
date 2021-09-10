/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:07:45 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/10 10:40:56 by apaula-b         ###   ########.fr       */
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

static char	*convert_positive(long int value, int size, char *string)
{
	int			last_value;
	int			counter;

	counter = 1;
	while (counter <= size)
	{
		last_value = value % 10;
		value /= 10;
		if (last_value < 10)
			string[counter] = (last_value * -1) + '0';
		else
			string[counter] = (last_value * -1) + 87;
		counter++;
	}
	string[size] = '\0';
	return (string);
}

static char	*convert_negative(int value, int size, char *string)
{
	int			last_value;
	int			counter;

	if (!value)
	{
		string = "0";
		return (string);
	}
	else
		string[0] = '-';
	counter = size;
	while (counter > 0)
	{
		last_value = value % 16;
		value /= 10;
		if (last_value > -10)
			string[counter] = (last_value * -1) + '0';
		else
			string[counter] = (last_value * -1) + 87;
		counter--;
	}
	return (string);
}

char	*ft_utoa(long int integer)
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
	if (integer < 0)
	{
		value = convert_negative(integer, size, value);
	}
	else
		value = convert_positive(integer, size, value);
	return (value);
}
