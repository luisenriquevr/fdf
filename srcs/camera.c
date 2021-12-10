/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:09:37 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/10 13:28:20 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	zoom(int size)
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

int	range(t_data *data)
{
	int	x;
	int	y;

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