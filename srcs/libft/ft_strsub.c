/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:10:51 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/08 17:10:53 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;
	char *save;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if ((str = ft_strnew(len)) != NULL)
	{
		save = str;
		while (len-- && s[start] != '\0')
			*save++ = s[start++];
		*save = '\0';
	}
	return (str);
}
