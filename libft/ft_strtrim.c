/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:40:58 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/13 00:36:36 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*copy;
	char	*str;
	int		i;

	str = (char *)s;
	if (str == '\0')
		return (NULL);
	i = ft_strlen(str);
	if (!(copy = (char *)malloc(sizeof(*copy) * (i + 1))))
		return (NULL);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	copy = ft_strdup(str);
	i = ft_strlen(str);
	while (str[i] == '\0' || str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		copy[i] = '\0';
		i--;
	}
	return (copy);
}
