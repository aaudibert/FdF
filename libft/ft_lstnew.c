/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 12:01:36 by jumiguel          #+#    #+#             */
/*   Updated: 2015/04/07 13:20:52 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if ((new->content = (void*)malloc(content_size)))
		{
			ft_memcpy(new->content, content, content_size);
			ft_memcpy(&new->content_size, &content_size, sizeof(size_t));
		}
		else
		{
			free(new);
			return (NULL);
		}
	}
	new->next = NULL;
	return (new);
}
