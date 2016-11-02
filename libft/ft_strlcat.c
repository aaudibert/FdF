/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:06:17 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/13 00:26:40 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(dst);
	if (i < size)
	{
		i = 0;
		while (dst[i] && i < size)
			i++;
		if ((size - ft_strlen(dst) - 1) > 0)
			ft_strncat(dst, src, (size - ft_strlen(dst) - 1));
		return (i + ft_strlen(src));
	}
	else
		return ((ft_strlen(src) + size));
}
