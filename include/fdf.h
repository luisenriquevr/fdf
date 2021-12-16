/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:55:34 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/16 14:31:32 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/minilibx-Darwin/mlx.h"
# include "keycode_mac.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

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

void	data_init(t_data *init);
void	camera_init(t_data *data);
void	map_parser(char *filename, t_data *data);
void	mlx_func_init(t_data *data);
int		key_press(int key, t_data *data);
int		exitt(t_data *data);
int		image_creator(t_data *data);
void	plotline(t_point p0, int x1, int y1, t_data *data);
void	clean_exit(t_data *data, char *info, int error);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	perform_zoom(t_point *p0, t_point *p1, int z[2], t_data *data);
void	perform_position(t_point *p0, t_point *p1, t_data *data);
void	ft_split(char const *s1, char c, t_data *d);

int		zoom_bonus(int button, int x, int y, t_data *data);
void	perspective(t_data *data, int key);
void	camera_mov(t_data *data, int key);
void	rotate(int *x, int *y, int *z, t_data *data);

#endif
