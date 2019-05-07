/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:47:14 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/05 18:47:16 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len;
	size_t len1;

	len = ft_strlen(s2) + 1;
	len1 = ft_strlen(s1);
	if (len >= n)
	{
		ft_memcpy(s1 + len1, s2, n);
		*(s1 + len1 + n) = '\0';
	}
	else
		ft_memcpy(s1 + len1, s2, len);
	return (s1);
}
