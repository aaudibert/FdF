/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ynext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:00:10 by aaudiber          #+#    #+#             */
/*   Updated: 2016/10/27 21:52:19 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

t_crd		*get_ynext(t_crd *map)
{
	t_crd *ret;
	t_crd *tmp;

	map = map->next;
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
