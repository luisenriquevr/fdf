/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:59:49 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/16 10:43:57 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *c, int x, int y, int color)
{
	if (x >= WID_CAM || x < 0 || y >= HEI_CAM || y < 0)
		return ;
	c->win.addr[c->win.width * y + x] = color;
}

int	set_color(int x, int y, t_data *data)
{
	int		z;
	float	i;

	z = data->map[y][x];
	i = (float)data->range.range / 6;
	if (z <= data->range.min + i)
		return (COLOR_1);
	else if (z <= (data->range.min + 2 * i))
		return (COLOR_2);
	else if (z <= (data->range.min + 3 * i))
		return (COLOR_3);
	else if (z <= (data->range.min + 4 * i))
		return (COLOR_4);
	else if (z <= (data->range.min + 5 * i))
		return (COLOR_5);
	else if (z <= (data->range.min + 6 * i))
		return (COLOR_6);
	return (0);
}

int	image_creator(t_data *data)
{
	t_point	point;

	point.y = 0;
	while (point.y < data->nrows)
	{
		point.x = 0;
		while (point.x < data->ncols)
		{
			data->color = set_color(point.x, point.y, data);
			if (point.x < data->ncols - 1)
				plotline(point, point.x + 1, point.y, data);
			if (point.y < data->nrows - 1)
				plotline(point, point.x, point.y + 1, data);
			point.x++;
		}
		point.y++;
	}
	mlx_put_image_to_window(data->libx.mlx, data->libx.window, data->win.img, 0, 0);
	return (1);
}
