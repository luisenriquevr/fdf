/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:50:49 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/01 18:14:22 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	max1(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	bresenham(float x, float y, float x1, float y1, t_data *data)
{
	float	x_step;
	float	y_step;
	int	max;

	x_step = x1 - x;
	y_step = y1 - y;
	max = max1(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y- y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		while (x < data->width)
		{
			bresenham(x, y, x + 1, y, data);
		}
	}
}
