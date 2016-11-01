/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 21:24:10 by aaudiber          #+#    #+#             */
/*   Updated: 2016/10/26 17:28:07 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

t_crd		*rewind_lst(t_crd *map)
{
	while (map->prev)
		map = map->prev;
	return (map);
}

t_crd		*link_push(t_crd *new, t_crd *curr)
{
	curr->next = new;
	new->next = NULL;
	new->prev = curr;
	return (curr);
}

t_crd		*new_link(int x, int y, int z, int val)
{
	t_crd *ret;

	ret = (t_crd *)malloc(sizeof(t_crd));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	ret->isx = 0;
	ret->isy = 0;
	ret->val = val;
	ret->ynext = NULL;
	return (ret);
}
