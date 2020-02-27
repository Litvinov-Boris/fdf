/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:42:17 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/06 22:42:18 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t l1;
	size_t l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 <= l2)
		l1 = l2;
	if (l1 < n)
		n = l1;
	return (ft_memcmp(s1, s2, n));
}
