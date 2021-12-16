/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:23:56 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/16 14:24:32 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	perform_zoom(t_point *p0, t_point *p1, int z[2], t_data *data)
{
	p0->x *= data->cam.zoom;
	p0->y *= data->cam.zoom;
	p1->x *= data->cam.zoom;
	p1->y *= data->cam.zoom;
	z[0] *= data->cam.zoom / 2;
	z[1] *= data->cam.zoom / 2;
}

void	perform_position(t_point *p0, t_point *p1, t_data *data)
{
	p0->x += data->cam.x;
	p0->y += data->cam.y;
	p1->x += data->cam.x;
	p1->y += data->cam.y;
}

static int	zoom(int size)
{
	if (size <= 20)
		return (ZOOM);
	else if (size <= 50)
		return (ZOOM / 2);
	else if (size < 150)
		return (ZOOM / 4);
	else
		return (2);
}

static void	range(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	data->range.max = __INT_MAX__ * -1;
	data->range.min = __INT_MAX__;
	while (y < data->nrows)
	{
		x = 0;
		while (x < data->ncols)
		{
			if (data->map[y][x] < data->range.min)
				data->range.min = data->map[y][x];
			if (data->map[y][x] > data->range.max)
				data->range.max = data->map[y][x];
			x++;
		}
		y++;
	}
	data->range.range = abs(data->range.max - data->range.min);
}

void	camera_init(t_data *data)
{
	range(data);
	data->cam.angle = ANGLE;
	data->cam.pangle = PERSPECTIVE_ANGLE;
	data->cam.isometric = ISOMETRIC;
	data->cam.plane = PLANE;
	data->cam.oblique = OBLIQUE;
	data->cam.zoom = zoom(data->ncols);
	data->cam.x = WID_CAM / 3 + 100;
	data->cam.y = HEI_CAM / 2;
	data->cam.rotate[0] = 0;
	data->cam.rotate[1] = 0;
	data->cam.rotate[2] = 0;
}
