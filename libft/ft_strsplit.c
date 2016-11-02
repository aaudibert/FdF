/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 15:36:23 by jumiguel          #+#    #+#             */
/*   Updated: 2016/10/26 16:47:45 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_str(char const *s, char c)
{
	int		i;
	int		ln;
	char	*str;

	str = (char *)s;
	ln = 0;
	i = 0;
	while (str[ln])
	{
		if ((str[ln - 1] != c && str[ln] == c) || str[ln + 1] == '\0')
			i++;
		ln++;
	}
	return (i);
}

char	*ft_recup_words(char *str, char c, int n)
{
	char	*copy;
	int		word;

	word = 0;
	while (str[n] != c && str[n])
	{
		word++;
		n++;
	}
	n = n - word;
	if (!(copy = (char *)malloc(sizeof(char) * (word + 1))))
		return (NULL);
	word = 0;
	while (str[n] != c && str[n])
	{
		copy[word] = str[n];
		n++;
		word++;
	}
	copy[word] = '\0';
	return (copy);
}

char	**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**tab;
	int		i;
	int		j;

	str = (char *)s;
	if (!str)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_count_str(str, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && str[i])
		{
			tab[j] = ft_recup_words(str, c, i);
			i = ft_strlen(tab[j]) + i - 1;
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
