/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:48:14 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/08 15:48:17 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *save;

	if (!s)
	{
		str = ft_strnew(0);
		return (str);
	}
	if ((str = ft_strnew(ft_strlen(s))) != NULL)
	{
		save = str;
		while (*s)
			*(save++) = f(*(s++));
	}
	return (str);
}
