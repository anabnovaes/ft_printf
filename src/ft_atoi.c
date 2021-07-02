/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:41:55 by apaula-b          #+#    #+#             */
/*   Updated: 2021/07/02 11:30:24 by apaula-b         ###   ########.fr       */
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
	int		counter;
	int		sum;
	int		signal;

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
