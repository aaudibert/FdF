/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 21:09:53 by jumiguel          #+#    #+#             */
/*   Updated: 2016/11/15 19:24:38 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

float		center_x(t_pad *p, int w)
{
	float	ret;
	int		tmpx;
	int		tmpy;

	tmpx = p->px * p->xm->x;
	tmpy = (p->px * (0 - p->ym->y)) * -1;
	ret = ((w - (tmpx + tmpy)) / 2) + tmpy;
	return (ret);
}

float		center_y(t_pad *p, int h)
{
	float ret;

	ret = (h - (p->py * (p->ym->y + p->ym->x))) / 2;
	return (ret);
}

void		get_max(t_pad *pad, t_crd *map)
{
	t_crd	*tmp;

	tmp = map;
	pad->xm = tmp;
	pad->ym = tmp;
	pad->zx = tmp;
	pad->zn = tmp;
	while (tmp)
	{
		if (tmp->val && tmp->x > pad->xm->x)
			pad->xm = tmp;
		if (tmp->val && tmp->y > pad->ym->y)
			pad->ym = tmp;
		if (tmp->val && tmp->z > pad->zx->z)
			pad->zx = tmp;
		if (tmp->val && tmp->z < pad->zx->z)
			pad->zn = tmp;
		tmp = tmp->next;
	}
}
