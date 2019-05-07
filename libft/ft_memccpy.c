/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:47:34 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/04 20:47:36 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
					size_t n)
{
	size_t i;

	i = 0;
	while (n - i)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		if (*(char*)(src + i) == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
