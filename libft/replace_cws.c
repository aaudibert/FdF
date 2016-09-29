/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_cws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:39:59 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/24 15:50:25 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			o_occ(char *s, char o, char *r)
{
	int i;
	int	x;

	i = -1;
	x = 0;
	while (s[++i])
	{
		if (s[i] == o)
			x++;
	}
	return (x * ft_strlen(r));
}

char		*replace_cws(char *s, char o, char *r)
{
	char	*ret;
	int		i;
	int		j;
	int		p;

	i = -1;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + o_occ(s, o, r)));
	while (s[++i] != '\0')
	{
		p = -1;
		if (s[i] == o)
		{
			while (r[++p] != '\0')
				ret[j++] = r[p];
		}
		else
			ret[j++] = s[i];
	}
	ret[j] = 0;
	free(s);
	return (ret);
}
