/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:00:48 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/06 23:00:50 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t len;

	if (*s2 != '\0')
	{
		len = ft_strlen(s2);
		while (*s1 && n >= len)
		{
			if (ft_strncmp(s1, s2, len) == 0)
				return ((char*)s1);
			s1++;
			n--;
		}
		return (NULL);
	}
	return ((char*)s1);
}
