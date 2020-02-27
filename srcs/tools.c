/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 02:37:46 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/15 03:21:19 by svivienn         ###   ########.fr       */
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