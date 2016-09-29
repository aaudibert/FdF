/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_cwc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:30:59 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/24 15:50:35 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*replace_cwc(char *s, char o, char r)
{
	int		i;
	char	*ret;

	i = -1;
	ret = (char *)malloc(sizeof(char) * ft_strlen(s));
	while (s[++i] != '\0')
	{
		if (s[i] == o)
			ret[i] = r;
		else
			ret[i] = s[i];
	}
	ret[i] = 0;
	free(s);
	return (ret);
}
