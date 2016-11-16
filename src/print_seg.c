/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_seg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:19:43 by aaudiber          #+#    #+#             */
/*   Updated: 2016/11/16 16:25:36 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

int		ft_color(int z1)
{
	int color;

	if (z1 <= 0)
		color = BLUE;
	else if (z1 <= 10)
		color = YELLOW;
	else if (z1 <= 60)
		color = GREEN;
	else if (z1 <= 90)
		color = DGREEN;
	else if (z1 <= 120)
		color = BROWN;
	else
		color = WHITE;
	return (color);
}

void	dx_sup_dy(t_env e, t_bres bsm, t_crd *map, t_crd *next)
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
		if (i >= bsm.dy / 2 && map->z - next->z <= -30)
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, ft_color(map->z + 30));
		else if (i >= bsm.dy / 2 && map->z -next->z >= 30)
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, ft_color(map->z - 30));
		else
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, ft_color(map->z));
		i++;
	}
}

void	dx_inf_dy(t_env e, t_bres bsm, t_crd *map, t_crd *next)
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
		if (i >= bsm.dy / 2 && map->z - next->z <= -30)
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, ft_color(map->z + 30));
		else if (i >= bsm.dy / 2 && map->z -next->z >= 30)
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, ft_color(map->z - 30));
		else
			mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, ft_color(map->z));
		i++;
	}
}

void	print_segment(t_env e, t_crd *map, t_crd *next)
{
	t_bres	bsm;

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
	mlx_pixel_put(e.mlx, e.win, bsm.xi, bsm.yi, ft_color(map->z));
	if (bsm.dx > bsm.dy)
		dx_sup_dy(e, bsm, map, next);
	else
		dx_inf_dy(e, bsm, map, next);
}
