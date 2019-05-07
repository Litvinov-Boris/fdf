/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:02:25 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/07 20:02:28 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			neg;
	long int	rez;

	neg = 1;
	rez = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r' ||
		*str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (rez > 0 && ((rez * 10) + (*str - '0') * neg) < 0)
			return (-1);
		if (rez < 0 && ((rez * 10) + (*str - '0') * neg) > 0)
			return (0);
		rez = (rez * 10) + (*str - '0') * neg;
		str++;
	}
	return ((int)rez);
}
