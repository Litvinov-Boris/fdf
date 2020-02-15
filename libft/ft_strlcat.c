/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:16:20 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/06 16:16:22 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (ft_strlen(d) >= size)
		return (size + ft_strlen(s));
	size -= ft_strlen(d);
	d += ft_strlen(d);
	while (*s != 0 && size != 1)
	{
		*(d++) = *(s++);
		size--;
	}
	*d = '\0';
	return (ft_strlen(dst) + ft_strlen(s));
}
