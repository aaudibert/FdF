/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_seg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:19:43 by aaudiber          #+#    #+#             */
/*   Updated: 2016/11/02 16:36:38 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	dx_sup_dy(t_env e, t_bres bsm, int color)
{
	int i;
	int cumul;

	i = 1;
	cumul = bsm.dx / 2;
	while (i <= bsm.dx)
	{
		bsm.xi += bsm.xinc;
		cumul += bsm.dy;
		if (cumul >= bsm.dx)
		{
			cumul -= bsm.dx;
			bsm.yi += bsm.yinc;
		}
		if (i >= bsm.dy / 2 && color == BLUE)
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, GREEN);
		if (i >= bsm.dy / 2 && color == GREEN)
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, BROWN);
		else
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, color);
		i++;
	}
}

void	dx_inf_dy(t_env e, t_bres bsm, int color)
{
	int i;
	int cumul;

	i = 1;
	cumul = bsm.dy / 2;
	while (i <= bsm.dy)
	{
		bsm.yi += bsm.yinc;
		cumul += bsm.dx;
		if (cumul >= bsm.dy)
		{
			cumul -= bsm.dy;
			bsm.xi += bsm.xinc;
		}
		if (i >= bsm.dy / 2 && color == BLUE)
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, GREEN);
		if (i >= bsm.dy / 2 && color == GREEN)
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, BROWN);
		else
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, color);
		i++;
	}
}

int		choose_color(int z1, int z2)
{
	int color;

	if (z1 <= 0 && z2 <= 0)
		color = BLUE;
	else if (z1 < z2)
		color = GREEN;
	else
		color = BROWN;
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
		dx_sup_dy(e, bsm, color);
	else
		dx_inf_dy(e, bsm, color);
}

