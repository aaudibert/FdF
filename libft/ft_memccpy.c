/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:58:45 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/07 23:04:38 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	*str1;

	str = (char *)dst;
	str1 = (char *)src;
	i = 0;
	while (i < n)
	{
		str[i] = str1[i];
		if (str[i] == (unsigned char)c)
			return (&str[i + 1]);
		i++;
	}
	return (NULL);
}
