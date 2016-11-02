/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:07:04 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/11 20:39:06 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(concat = (char *)malloc(sizeof(*concat) * i)))
		return (NULL);
	i = -1;
	while (s1[++i])
		concat[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i])
	{
		concat[j] = s2[i];
		j++;
	}
	concat[j] = '\0';
	return (concat);
}
