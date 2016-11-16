/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:22:48 by jumiguel          #+#    #+#             */
/*   Updated: 2016/11/15 19:26:41 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# define RESET			"\x1B[0m"
# define RED			"\x1B[31m"

# define WHITE			0xFFFFFF
# define MAGENTA		0xFF0000
# define BLUE			0x000FFF
# define GREEN			0x00FF00
# define DGREEN			0x009900
# define BROWN			0x613109
# define YELLOW			0xedda10

# define MX				map->x
# define MY				map->y
# define MZ				map->z
# define MLX			e.mlx
# define WIN			e.win

typedef struct			s_bres
{
	float				xi;
	float				yi;
	float				xf;
	float				yf;
	float				dx;
	float				dy;
	int					xinc;
	int					yinc;
}						t_bres;

typedef struct			s_img
{
	void				*ptr_img;
	char				*data;
	int					sl;
	int					endian;
	int					bpp;
}						t_img;

typedef struct			s_crd
{
	int					x;
	int					y;
	int					z;
	float				isx;
	float				isy;
	int					val;
	struct s_crd		*next;
	struct s_crd		*prev;
	struct s_crd		*ynext;
}						t_crd;

typedef struct			s_pad
{
	float				px;
	float				py;
	float				cx;
	float				cy;
	float				ct;
	t_crd				*xm;
	t_crd				*ym;
	t_crd				*zx;
	t_crd				*zn;
}						t_pad;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_crd				*map;
	t_img				*img;
	int					h;
	int					w;
}						t_env;

int						get_next_line(int const fd, char **line);
t_crd					*create_map(char *file);
t_crd					*get_ynext(t_crd *map);
void					err_func(char *err);
int						wrong_extension(char *file);
t_crd					*new_link(int x, int y, int z, int val);
t_crd					*link_push(t_crd *nw, t_crd *curr);
t_crd					*rewind_lst(t_crd *map);
t_crd					*get_ynext(t_crd *map);
void					iso_map(t_crd *map, int h, int w);
void					get_max(t_pad *pad, t_crd *map);
float					center_x(t_pad *p, int w);
float					center_y(t_pad *p, int h);
void					print_segment(t_env e, t_crd *map, t_crd *next);
void					del_crd(t_crd *m);
#endif
