/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:26:13 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/08 19:31:52 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			copy[i] = f(i, str[i]);
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);
}
