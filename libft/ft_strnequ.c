/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:39:11 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/08 15:43:13 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str1 == '\0' || str2 == '\0')
		return (0);
	while (*str1 && *str2 && *str1 == *str2 && n)
	{
		str1++;
		str2++;
		n--;
	}
	if (ft_strncmp(str1, str2, n) == 0 || !n)
		return (1);
	else
		return (0);
}
