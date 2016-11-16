/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ynext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:00:10 by aaudiber          #+#    #+#             */
/*   Updated: 2016/11/16 16:26:10 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

t_crd		*get_ynext(t_crd *map)
{
	t_crd *ret;
	t_crd *tmp;

	tmp = map;
	ret = map->next;
	while (tmp)
	{
		ret = tmp->next;
		while (ret)
		{
			if (ret && (ret->y == (tmp->y + 1)) && tmp->x == ret->x)
			{
				tmp->ynext = ret;
				break ;
			}
			ret = ret->next;
		}
		tmp = tmp->next;
	}
	return (map);
}
