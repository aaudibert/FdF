/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:03:59 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/13 00:27:17 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*copy;
	char	*str;
	int		i;

	str = (char *)s;
	if (str && f)
	{
		i = ft_strlen(str);
		if (!(copy = (char *)malloc(sizeof(*copy) * (i + 1))))
			return (NULL);
		i = 0;
		while (str[i] != '\0')
		{
			copy[i] = f(str[i]);
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);
}
