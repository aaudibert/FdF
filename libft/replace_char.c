/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:30:16 by jumiguel          #+#    #+#             */
/*   Updated: 2016/09/01 16:40:39 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*replace_char(char *s, char o, char r)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i])
	{
		if (s[i] == o)
			ret[i] = r;
		else
			ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	free(s);
	return (ret);
}
