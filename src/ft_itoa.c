/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:03:26 by apaula-b          #+#    #+#             */
/*   Updated: 2021/09/09 20:33:27 by apaula-b         ###   ########.fr       */
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
	check_value = value / 10 ;
	while (check_value >= 1)
	{
		check_value /= 10 ;
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
		string[size - counter] = last_value + '0';
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
		last_value = value % 10;
		value /= 10;
		string[counter] = (last_value * -1) + '0';
		counter--;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	char		*value;
	int			size;
	int			spaces;

	spaces = 0;
	size = check_size(n);
	if (n < 0)
		spaces = 1;
	value = ft_calloc(sizeof(char), size + 1 + spaces);
	if (!value)
		return (NULL);
	if (n < 0)
	{
		value = convert_negative(n, size, value);
	}
	else
		value = convert_positive(n, size, value);
	return (value);
}
