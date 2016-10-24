/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ynext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:00:10 by aaudiber          #+#    #+#             */
/*   Updated: 2016/10/24 18:45:06 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

t_crd		*get_ynext(t_crd *map)
{
	t_crd *ret;
	t_crd *tmp;

	ret = map;
	map = map->next;
	tmp = map->next;
	while (map)
	{
		while (tmp && (tmp->x != map->x) && (tmp->y != (map->y + 1)))
			tmp = tmp->next;
		if (!tmp || !map->next)
		{
			map->ynext = NULL;
			tmp = map->next;
		}
		else
		{
			ft_putstr("curr --> x = ");
			ft_putnbr(map->x);
			ft_putstr(", y = ");
			ft_putnbr(map->y);
			ft_putstr(" || ynext --> x = ");
			ft_putnbr(tmp->x);
			ft_putstr(", y = ");
			ft_putnbr(tmp->y);
			ft_putchar('\n');
			map->ynext = tmp;
		}
		map = map->next;
		if (map->next)
			tmp = map->next;
	}
	return (ret);
}
