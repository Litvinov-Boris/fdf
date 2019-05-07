/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:22:29 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/10 16:22:31 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *el;

	if (lst && f)
	{
		if ((el = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		{
			el->next = ft_lstmap(lst->next, f);
			return (el);
		}
	}
	return (NULL);
}
