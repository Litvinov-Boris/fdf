/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:24:12 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/08 18:24:14 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;
	char	*save;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (len && (s[len - 1] == ' ' || s[len - 1] == '\n' ||
				s[len - 1] == '\t'))
		len--;
	if (len == 0)
		return (ft_strnew(0));
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s++;
		len--;
	}
	if ((str = ft_strnew(len)) != NULL)
	{
		save = str;
		while (len--)
			*save++ = *s++;
		*save = '\0';
	}
	return (str);
}
