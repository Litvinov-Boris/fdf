/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:21:35 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/06 19:21:37 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *rez;

	rez = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			rez = (char*)s;
		s++;
	}
	if (*s == (char)c)
		rez = (char*)s;
	return (rez);
}
