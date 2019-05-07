/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:27:26 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/10 15:27:28 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	if ((elem = (t_list*)malloc(sizeof(t_list))) != NULL)
	{
		elem->next = NULL;
		if (content)
		{
			if (!(elem->content = ft_memalloc(content_size)))
			{
				free(elem);
				return (NULL);
			}
			ft_memcpy(elem->content, content, content_size);
			elem->content_size = content_size;
		}
		else
		{
			elem->content = NULL;
			elem->content_size = 0;
		}
		return (elem);
	}
	return (NULL);
}
