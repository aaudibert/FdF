/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 14:03:22 by jumiguel          #+#    #+#             */
/*   Updated: 2016/09/02 15:15:08 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*temp2;

	if (*alst)
	{
		temp = (*alst)->next;
		while (temp)
		{
			(*del)(temp->content, temp->content_size);
			temp2 = temp->next;
			free(temp);
			temp = temp2;
		}
		ft_lstdelone(alst, (*del));
	}
}
