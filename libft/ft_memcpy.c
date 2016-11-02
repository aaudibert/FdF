/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:02:47 by jumiguel          #+#    #+#             */
/*   Updated: 2016/09/01 15:52:24 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}
