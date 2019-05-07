/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:33:58 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/09 16:34:00 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennum(int n)
{
	int i;

	i = 1;
	while (n >= 10 || n <= -10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;

	len = lennum(n);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		len++;
	}
	if ((str = ft_strnew(len)) != NULL)
	{
		while (--len)
		{
			str[len] = (n % 10 * sign) + '0';
			n /= 10;
		}
		if (sign == -1)
			str[0] = '-';
		else
			str[0] = (n % 10 * sign) + '0';
	}
	return (str);
}
