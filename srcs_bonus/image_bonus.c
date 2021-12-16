/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:53:53 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/16 15:02:58 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (x >= WID_CAM || x < 0 || y >= HEI_CAM || y < 0)
		return ;
	data->win.addr[data->win.width * y + x] = color;
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

static void	controls_print(void *mlx, void *window)
{
	int	x;

	x = 200 / 5;
	mlx_string_put(mlx, window, x, 40, COLOR_6, "CONTROLS");
	mlx_string_put(mlx, window, x, 45, COLOR_5, "________");
	mlx_string_put(mlx, window, x, 70, COLOR_1, "Zoom: Scroll");
	mlx_string_put(mlx, window, x, 100, COLOR_1, "Move");
	mlx_string_put(mlx, window, x, 105, COLOR_5, "____");
	mlx_string_put(mlx, window, x, 130, COLOR_3, "W -> Up");
	mlx_string_put(mlx, window, x, 150, COLOR_3, "S -> Down");
	mlx_string_put(mlx, window, x, 170, COLOR_3, "A -> Left");
	mlx_string_put(mlx, window, x, 190, COLOR_3, "D -> Right");
	mlx_string_put(mlx, window, x, 220, COLOR_1, "Projection");
	mlx_string_put(mlx, window, x, 225, COLOR_5, "__________");
	mlx_string_put(mlx, window, x, 250, COLOR_3, "I -> Isometric");
	mlx_string_put(mlx, window, x, 270, COLOR_3, "P -> Plane");
	mlx_string_put(mlx, window, x, 290, COLOR_3, "O -> Oblique");
	mlx_string_put(mlx, window, x, 320, COLOR_1, "Rotation: Arrows");
	mlx_string_put(mlx, window, x, 325, COLOR_5, "________________");
	mlx_string_put(mlx, window, x, 350, COLOR_3, "Left -> X Axis");
	mlx_string_put(mlx, window, x, 370, COLOR_3, "Right -> Y Axis");
	mlx_string_put(mlx, window, x, 390, COLOR_3, "Up -> Z Axis");
	mlx_string_put(mlx, window, x, 410, COLOR_3, "Down -> Reset");
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
	controls_print(data->libx.mlx, data->libx.window);
	mlx_mouse_hook(data->libx.window, zoom_bonus, data);
	return (1);
}
