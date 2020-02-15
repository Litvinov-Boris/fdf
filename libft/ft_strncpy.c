/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:59:40 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/05 16:59:41 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t n;

	n = ft_strlen(src) + 1;
	if (n >= len)
		ft_memcpy(dst, src, len);
	else
	{
		ft_memcpy(dst, src, n);
		ft_bzero(dst + n, len - n);
	}
	return (dst);
}
