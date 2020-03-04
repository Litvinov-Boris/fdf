/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 02:37:46 by svivienn          #+#    #+#             */
/*   Updated: 2020/03/04 05:01:31 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error()
{
	perror("error");
	exit(1);
}

void	put_tail(t_list **head, t_list **tail, void *content)
{
	t_list	*work;

	work = ft_lstnew(0,0);
	work->content = content;
	if (*head == NULL)
	{
		*head = work;
		*tail = work;
	}
	else
	{
		(*tail)->next = work;
		(*tail) = (*tail)->next;
	}
}

int		atoi_hex(char *str)
{
	int		rez;

	rez = 0;
	if (*str == '0' && *(str+1) == 'x')
		str += 2;
	else
		return rez;
	while (*str != '\0')
	{
		rez *= 16;
		if (*str <= '9' && *str >= '0')
			rez += *str - 48;
		else if (*str >= 'A' && *str <= 'Z')
			rez += *str - 55;
		else if (*str >= 'a' && *str <= 'z')
			rez += *str - 87;
		else
		{
			rez /= 16;
			return (rez);
		}
		str++;
	}
	return (rez);
}
