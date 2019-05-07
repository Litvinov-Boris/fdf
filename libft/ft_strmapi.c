/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:26:12 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/08 16:26:14 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*save;

	if (!s)
	{
		str = ft_strnew(0);
		return (str);
	}
	i = 0;
	if ((str = ft_strnew(ft_strlen(s))) != NULL)
	{
		save = str;
		while (*s)
			*(save++) = f(i++, *(s++));
	}
	return (str);
}
