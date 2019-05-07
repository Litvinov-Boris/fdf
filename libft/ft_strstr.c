/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:30:41 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/06 19:30:42 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t ln;

	ln = ft_strlen(needle);
	if (ln == 0)
		return ((char*)haystack);
	while (*haystack)
	{
		if (!ft_memcmp(haystack, needle, ln))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
