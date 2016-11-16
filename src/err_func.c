/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 17:18:01 by jumiguel          #+#    #+#             */
/*   Updated: 2016/11/15 19:23:59 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

int			wrong_extension(char *file)
{
	char *tmp;

	tmp = ft_strsub(file, (ft_strlen(file) - 4), 4);
	if (ft_strcmp(tmp, ".fdf"))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

void		err_func(char *s)
{
	ft_putendl_color(s, RED);
	exit(0);
}
