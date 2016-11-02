/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:16:32 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/14 21:46:09 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < n && *str2 && str1[i])
	{
		j = 0;
		while (i + j < n && str1[i + j] == str2[j] && str1[i + j] && str2[j])
			j++;
		if (str1[i + j] == '\0' && str2[j])
			return (NULL);
		if (str2[j] == '\0')
			return (str1 + i);
		i++;
	}
	if (*str2 == '\0' && str1)
		return (str1);
	else
		return (NULL);
}
