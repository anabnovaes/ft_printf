/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AnaNovaes-MBA <AnaNovaes-MBA@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:41:55 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/19 20:40:12 by AnaNovaes-M      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	check_signal(char value)
{
	if (value == '-')
		return (-1);
	else if (value == '+')
		return (1);
	else
		return (0);
}

static int	check_spaces(char character)
{
	if (character == ' ' || character == '\v' || character == '\n'
		|| character == '\t' || character == '\r' || character == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t		counter;
	size_t		sum;
	size_t		signal;

	counter = 0;
	sum = 0;
	signal = 1;
	while (check_spaces(str[counter]))
		counter++;
	if (check_signal(str[counter]))
	{
		signal = check_signal(str[counter]);
		counter++;
	}
	while (ft_isdigit(str[counter]))
	{
		sum = (sum * 10) + (str[counter] - '0');
		counter++;
	}
	return (sum * signal);
}
