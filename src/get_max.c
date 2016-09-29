/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 21:09:53 by aaudiber          #+#    #+#             */
/*   Updated: 2016/09/28 18:44:13 by aaudiber         ###   ########.fr       */
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
	while (tmp)
	{
		if (tmp->val && tmp->x > pad->xm->x)
			pad->xm = tmp;
		if (tmp->val && tmp->y > pad->ym->y)
			pad->ym = tmp;
		tmp = tmp->next;
	}
}