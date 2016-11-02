/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:28:12 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/08 16:46:51 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	n = n - 1;
	while (n && str[i] == str1[i] && str[i] && str1[i])
	{
		i++;
		n--;
	}
	if (str[i] != str1[i])
		return (str[i] - str1[i]);
	else
		return (0);
}
