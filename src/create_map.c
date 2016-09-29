/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 23:33:43 by aaudiber          #+#    #+#             */
/*   Updated: 2016/09/28 18:35:17 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

t_crd			*get_number(char **map, t_crd *cd, int y)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i] && map[i][j])
		{
			if ((!ft_isdigit(map[i][j]) && map[i][j] != '-') ||
					(map[i][j] == '-' && j != 0))
			{
				j = -1;
				cd = (link_push(new_link(i, y, 0, 0), cd))->next;
				i++;
			}
			j++;
		}
		if (map[i])
			cd = (link_push(new_link(i, y, ft_atoi(map[i]), 1), cd))->next;
		else
			break ;
	}
	return (cd);
}

t_crd		*get_map_val(char *map)
{
	char	**tmp;
	char	**tmp2;
	int		y;
	t_crd	*ret;

	tmp = ft_strsplit(map, '\n');
	free(map);
	y = 0;
	ret = new_link(0, 0, 0, 0);
	ret->prev = NULL;
	while (tmp[y])
	{
		tmp2 = ft_strsplit(tmp[y], ' ');
		ret = get_number(tmp2, ret, y);
		ft_free_arr(tmp2);
		y++;
	}
	ft_free_arr(tmp);
	ret = rewind_lst(ret);
	return (ret);
}

char		*copy_map(char *tmp, char *line)
{
	char *ret;
	char *tmp2;

	if (!tmp)
		return (ft_strjoin(line, "\n"));
	else
	{
		tmp2 = ft_strjoin(line, "\n");
		ret = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		return (ret);
	}
}

t_crd		*create_map(char *file)
{
	t_crd	*map;
	int		fd;
	char	*line;
	char	*tmp;

	tmp = NULL;
	map = (t_crd *)malloc(sizeof(t_crd));
	map->x = 0;
	if (wrong_extension(file))
		err_func("Map must be in the following format: name.fdf");
	if ((fd = open(file, O_RDONLY)) == -1)
		err_func("File can't be opened.");
	while (get_next_line(fd, &line) == 1)
		tmp = copy_map(tmp, line);
	return (map = get_map_val(tmp));
}
