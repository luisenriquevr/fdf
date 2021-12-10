/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:55:34 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/10 13:28:36 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libs/libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../libs/get_next_line/get_next_line.h"
#include <math.h>
# define WID_CAM			1000
# define HEI_CAM			800
# define ZOOM				8
# define ANGLE				0.1
# define PERSPECTIVE_ANGLE	0.53
# define ISOMETRIC			1
# define PLANE				0
# define OBLIQUE			0
# define PERSPECTIVE_ANGLE2	0.2
# define ISOMETRIC0			0
# define PLANE1				1
# define OBLIQUE1			1
# define COLOR_1			0x00ffdc
# define COLOR_2			0xff6b38
# define COLOR_3			0xffffff
# define COLOR_4			0xe23030
# define COLOR_5			0x0083ff
# define COLOR_6			0xffec00
# define ROT_X				1
# define ROT_Y				2
# define ROT_Z				3


typedef struct s_render
{
	int			x;
	int			y;
}				t_render;

typedef struct s_minilibx
{
	void		*mlx;
	void		*window;
}				t_minilix;

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			height;
	int			width;
	int			sz;
	int			endian;
	int			bpp;
}				t_img;

typedef struct s_read
{
	char		*b;
	char		*l;
	char		**buf;
}				t_read;

typedef struct s_cam
{
	float		pangle;
	int			zoom;
	int			x;
	int			y;
	float		angle;
	int			isometric;
	int			oblique;
	int			plane;
	int			rotate[3];
}				t_cam;

typedef struct s_range
{
	int			max;
	int			min;
	int			range;
}				t_range;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_vbles
{
	int			x;
	int			y;
	int			d;
	int			dy;
	int			dx;
	int			xi;
	int			yi;
}				t_vbles;

typedef struct s_data
{
	int			nrows;
	int			ncols;
	char		*line;
	int			**map;
	int			color;
	int			zoom;
	int			mov;
	t_render	res;
	t_minilix	libx;
	t_img		win;
	t_cam		cam;
	t_range		range;
	t_read		read;
}				t_data;

void	map_parser(char *file_name, t_data *data);
void	camera_init(t_data *data);


#endif
