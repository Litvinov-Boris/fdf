/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:23:52 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/05 15:23:54 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *save;

	save = (unsigned char*)s;
	while (n--)
	{
		if (*save == (unsigned char)c)
			return (save);
		save++;
	}
	return (NULL);
}
