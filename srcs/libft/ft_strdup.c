/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:21:20 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/05 16:21:22 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1) + 1;
	if ((copy = (char*)malloc(sizeof(char) * len)) != NULL)
	{
		ft_memcpy(copy, s1, len);
		return (copy);
	}
	else
		return (NULL);
}
