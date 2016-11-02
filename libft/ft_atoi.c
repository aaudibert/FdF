/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:51:19 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/13 22:47:26 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calc_atoi(const char *str, int i, int n)
{
	int		j;

	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (j != 0)
			n = n * 10;
		n = n + (str[i] - '0');
		i++;
		j++;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		min;
	int		n;

	i = 0;
	min = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		min = -1;
	}
	n = calc_atoi(str, i, n);
	if (n == 0)
		return (0);
	else
		return (n * min);
}
