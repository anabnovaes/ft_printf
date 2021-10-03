/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 22:31:23 by apaula-b          #+#    #+#             */
/*   Updated: 2021/10/03 00:46:40 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_isalpha(size_t c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

size_t	ft_isdigit(size_t c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_isflag(size_t str)
{
	return (str == '-' || str == '0');
}

size_t	ft_isconversion(t_p *p_data)
{
	return (p_data->precision || p_data->width);
}
