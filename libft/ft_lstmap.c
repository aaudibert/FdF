/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 14:25:26 by jumiguel          #+#    #+#             */
/*   Updated: 2015/04/07 14:37:06 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (!(new = (*f)(lst)))
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = (*f)(lst)))
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (begin);
}
