/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AnaNovaes-MBA <AnaNovaes-MBA@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:03:08 by apaula-b          #+#    #+#             */
/*   Updated: 2021/06/19 20:42:26 by AnaNovaes-M      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size_s1;
	unsigned int	size_s2;
	char			*join;

	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = malloc(size_s1 + size_s2 + 1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, size_s1 + 1);
	ft_strlcat(join, s2, size_s2 + size_s1 + 1);
	return (join);
}
