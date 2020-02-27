/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:13:02 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/05 14:13:03 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s1;
	unsigned char *s2;

	if (!len)
		return (dst);
	if (src >= dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		s1 = (unsigned char*)(dst + len);
		s2 = (unsigned char*)(src + len);
		while (len--)
			*(--s1) = *(--s2);
		return (dst);
	}
}
