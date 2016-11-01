/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:23:11 by aaudiber          #+#    #+#             */
/*   Updated: 2016/10/27 18:51:07 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

int		key_hook(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	e.w = 1920;
	e.h = 1080;
	if (ac != 2)
	{
		ft_putendl("FdF: Wrong number of arguments");
		return (1);
	}
	e.map = create_map(av[1]);
	iso_map(e.map, e.h, e.w);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, e.w, e.h, "FdF");
	mlx_key_hook(WIN, key_hook, &e);
	while (e.map)
	{
			if (e.map->next && e.map->next->y == e.map->y && e.map->next->val && e.map->val)
				print_segment(e, e.map, e.map->next);
			if (e.map->ynext && e.map->ynext->val && e.map->val)
				print_segment(e, e.map, e.map->ynext);
/*		if (e.map->ynext && e.map->ynext->val && e.map->ynext->z == 0)
			mlx_pixel_put(e.mlx, e.win, e.map->ynext->isx, e.map->ynext->isy, WHITE);
		else if (e.map->ynext && e.map->ynext->val && e.map->ynext->z > 0)
			mlx_pixel_put(e.mlx, e.win, e.map->ynext->isx, e.map->ynext->isy, GREEN);
		else if (e.map->ynext && e.map->ynext->val && e.map->ynext->z < 0)
			mlx_pixel_put(e.mlx, e.win, e.map->ynext->isx, e.map->ynext->isy, MAGENTA);
		else if (e.map->ynext)
			mlx_pixel_put(e.mlx, e.win, e.map->ynext->isx, e.map->ynext->isy, BLUE);*/
		e.map = e.map->next;
	}
	mlx_loop(e.mlx);
	return (0);
}
