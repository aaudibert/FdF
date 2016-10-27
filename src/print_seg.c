/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_seg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:19:43 by aaudiber          #+#    #+#             */
/*   Updated: 2016/10/27 21:28:26 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	dx_sup_dy(void *mlx, void *win, t_bres bsm, int color)
{
	int i;
	int cumul;
	int x;
	int y;

	x = bsm.xi;
	y = bsm.yi;
	i = 1;
	cumul = bsm.dx / 2*
	while (i <= bsm.dx)
	{
		x += bsm.xinc;
		cumul += bsm.dy;
		if (cumul >= bsm.dx)
		{
			cumul -= bsm.dx;
			y += bsm.yinc;
		}
		mlx_pixel_put(mlx, win, x, y, color);
		i++;
	}
}

void	dx_inf_dy(void *mlx, void *win, t_bres bsm, int color)
{
	int i;
	int cumul;
	int x;
	int y;

	x = bsm.xi;
	y = bsm.yi;
	i = 1;
	cumul = bsm.dy / 2;
	while (i <= bsm.dy)
	{
		y += bsm.yinc;
		cumul += bsm.dx;
		if (cumul >= bsm.dy)
		{
			cumul -= bsm.dy;
			x += bsm.xinc;
		}
		mlx_pixel_put(mlx, win, x, y, color);
		i++;
	}
}

int		choose_color(int z1, int z2)
{
	int color;

	if (z1 != 0 && z2 != 0 && (z1 == z2))
		color = 0xFF0000;
	else if ((z1 != 0 && z2 > z1) || (z2 != 0 && z1 > z2))
		color = 0xFF00FF;
	else
		color = 0x0000FF;
	return (color);
}

void	print_segment(t_env e, t_crd *map, t_crd *next)
{
	t_bres	bsm;
	int		color;

	color = choose_color(map->z, next->z);
	bsm.xi = map->isx;
	bsm.yi = map->isy;
	bsm.xf = next->isx;
	bsm.yf = next->isy;
	bsm.dx = bsm.xf - bsm.xi;
	bsm.dy = bsm.yf - bsm.yi;
	bsm.xinc = (bsm.dx > 0) ? 1 : -1;
	bsm.yinc = (bsm.dy > 0) ? 1 : -1;
	if (bsm.dx < 0)
		bsm.dx = bsm.dx * -1;
	if (bsm.dy < 0)
		bsm.dy = bsm.dy * -1;
	mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, color);
	if (bsm.dx > bsm.dy)
		dx_sup_dy(e.mlx, e.win, bsm, color);
	else
		dx_inf_dy(e.mlx, e.win, bsm, color);
}

