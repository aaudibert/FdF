/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 19:16:25 by jumiguel          #+#    #+#             */
/*   Updated: 2016/09/01 16:39:58 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_arr(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return (1);
	while (array[i])
	{
		ft_putendl(array[i]);
		i++;
	}
	return (0);
}
