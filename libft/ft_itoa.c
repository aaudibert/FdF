/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 19:49:21 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/28 21:02:40 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size_lenght(int n, int *size)
{
	int	i;
	int negative;

	negative = 0;
	if (n < 0)
		negative = 1;
	i = 0;
	*size = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		*size *= 10;
		i++;
	}
	return (i + negative);
}

int		ft_result(int n)
{
	if (n < 0)
		n = -n;
	n += '0';
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		size;
	int		i;

	len = ft_size_lenght(n, &size);
	if ((str = ft_strnew(len)))
	{
		i = 0;
		if (n < 0)
		{
			str[i] = '-';
			n = -n;
			i++;
		}
		while (i < len)
		{
			str[i] = (ft_result(n / size) % 10);
			size /= 10;
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
