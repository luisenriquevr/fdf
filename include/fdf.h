/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:55:34 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/04 18:50:22 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libs/libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../libs/get_next_line/get_next_line.h"
#include <math.h>

typedef struct	s_data
{
	float	x;
	float	y;
	float	z;
	int	is_last;
	int	color;
	int	scale;
	int	z_scale;
	int	shift_x;
	int	shift_y;
	int	is_isomtric;
	double	angle;
	int	width;
	int	height;
	int	**z_matrix;
	int	zoom;
	int	color;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

void	map_parser(char *file_name, t_data *data);
void	bressenham(float x, float y, float x1, float y1, t_data *data);
void	draw(t_data *data);
void	checker(int argc, char **argv);

#endif
