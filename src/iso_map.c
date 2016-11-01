/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 23:25:24 by aaudiber          #+#    #+#             */
/*   Updated: 2016/10/24 18:03:34 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

t_pad		*get_pad(t_crd *map, int w, int h)
{
	t_pad *ret;

	ret = (t_pad *)malloc(sizeof(t_pad));
	ret->ct = 1;
	get_max(ret, map);
	ret->px = (w / ret->xm->x);
	ret->py = (h / ret->ym->y) / 2;
	ret->cx = center_x(ret, w);
	ret->cy = center_y(ret, h);
	if (ret->px > (ret->py * 2))
		ret->px /= 2;
	else if (ret->py > (ret->px * 2))
		ret->py /= 2;
	if (ret->px < 5)
		ret->px = 7;
	if (ret->py < 5)
		ret->py = 7;
	return (ret);
}

void		iso_map(t_crd *orig, int h, int w)
{
	t_crd	*map;
	t_pad	*pad;

	map = orig;
	pad = get_pad(map, w, h);
	while (map)
	{
		map->isx = ((pad->px / 2) * (MX - MY)) + pad->cx;
		map->isy = ((pad->py / 2) * (MX + MY - (MZ * pad->ct))) + (pad->cy / 2);
		if (map->next)
			map = map->next;
		else
			break ;
	}
	rewind_lst(map);
/*	while (orig)
	{
		if (orig->val)
		{
			ft_putstr("x = ");
			ft_putnbr(orig->x);
			ft_putstr(", y = ");
			ft_putnbr(orig->y);
			ft_putstr(", z = ");
			ft_putnbr(orig->z);
			ft_putstr(", isx = ");
			ft_putnbr(orig->isx);
			ft_putstr(", isy = ");
			ft_putnbr(orig->isy);
			if (orig->ynext)
			{
				ft_putstr(" || ynext --> ");
			ft_putstr("x = ");
			ft_putnbr(orig->ynext->x);
			ft_putstr(", y = ");
			ft_putnbr(orig->ynext->y);
			ft_putstr(", z = ");
			ft_putnbr(orig->ynext->z);
			}
			ft_putchar('\n');
		}
		orig = orig->next;
	}*/
}
