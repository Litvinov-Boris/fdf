/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:40:56 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/09 20:40:58 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**clear(char **str, char **save)
{
	while (save >= str)
	{
		free(*save);
		save--;
	}
	free(str);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	n;
	char	**save;

	if (s)
	{
		n = ft_countwords(s, c);
		if ((str = (char**)malloc(sizeof(*str) * (n + 1))) != NULL)
		{
			save = str;
			while (n--)
			{
				while (*s == c && *s != '\0')
					s++;
				if ((*save = ft_strsub(s, 0, ft_lenword(s, c))) == NULL)
					return (clear(str, save));
				save++;
				s = s + ft_lenword(s, c);
			}
			*save = NULL;
			return (str);
		}
	}
	return (NULL);
}
