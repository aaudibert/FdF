/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ynext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:00:10 by aaudiber          #+#    #+#             */
/*   Updated: 2016/10/24 17:19:56 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

t_crd		*get_ynext(t_crd *map)
{
	t_crd *ret;
	t_crd *tmp;

	ret = map;
	tmp = map->next;
	while (map)
	{
		while ((tmp->x != map->x) && (tmp->y == (map->y + 1)))
			tmp = tmp->next;
		if (!tmp)
		{
			map->ynext = NULL;
			tmp = map->next;
		}
		else
			map->ynext = tmp;
		map = map->next;
	}
	return (ret);
}
