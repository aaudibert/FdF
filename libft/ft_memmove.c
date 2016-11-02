/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:49:05 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/13 00:18:41 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*stmp;
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = 0;
	if (!(stmp = (unsigned char*)malloc(sizeof(*stmp) * len + 1)))
		return (NULL);
	while (i < len)
	{
		stmp[i] = str2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		str1[i] = stmp[i];
		i++;
	}
	free(stmp);
	return (dst);
}
