/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:16:32 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/13 00:31:54 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	int		len;

	str1 = (char *)s1;
	str2 = (char *)s2;
	len = ft_strlen(str2);
	if (len == 0)
		return (str1);
	while (*str1 != '\0')
	{
		if (ft_strncmp(str1, str2, len) == 0)
			return (str1);
		str1++;
	}
	return (NULL);
}
