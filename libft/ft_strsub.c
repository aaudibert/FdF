/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:51:25 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/13 12:26:28 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*copy;
	char		*str;

	str = (char *)s;
	if (str == '\0')
		return (NULL);
	if (!(copy = (char *)malloc(sizeof(*copy) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
