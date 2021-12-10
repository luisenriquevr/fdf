/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:42:46 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/10 14:24:40 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	data_init_aux(t_data *init)
{
	init->cam.pangle = 0.0;
	init->cam.zoom = 0;
	init->cam.x = 0;
	init->cam.y = 0;
	init->cam.angle = 0.0;
	init->cam.isometric = 0;
	init->cam.oblique = 0;
	init->cam.pangle = 0;
	init->cam.rotate[0] = 0;
	init->cam.rotate[1] = 0;
	init->cam.rotate[2] = 0;
	init->range.max = 0;
	init->range.min = 0;
	init->range.range = 0;
	init->zoom = 0;
	init->mov = 0;
	
}

void	data_init(t_data *init)
{
	data_init_aux(init);
	init->res.x = WID_CAM;
	init->res.y = HEI_CAM;
	init->line = NULL;
	init->map = NULL;
	init->libx.mlx = NULL;
	init->libx.window = NULL;
	init->win.img = NULL;
	init->win.addr = NULL;
	init->win.bpp = 0;
	init->win.endian = 0;
	init->win.sz = 0;
	init->win.width = 0;
	init->win.height = 0;
	init->ncols = 0;
	init->nrows = 0;
	init->read.b = NULL;
	init->read.l = NULL;
	init->read.buf = NULL;
}

static void	window_resize(t_data *data)
{
	if (data->res.x <= data->win.width)
		data->win.width = data->res.x;
	if (data->res.y <= data->win.height)
		data->win.height = data->res.y;
}

void	mlx_func_init(t_data *data)
{
	data->libx.mlx = mlx_init();
	if (!data->libx.mlx)
		clean_exit(data, "MLX was not initialized\n", 1);
	mlx_get_screen_size(data->libx.mlx, &data->win.width, &data->win.height);
	window_resize(data);
	data->libx.window = mlx_new_window(data->libx.mlx, data->win.width,
			data->win.height, "FdF");
	if (!data->libx.window)
		return (clean_exit(data, "When opening a new window\n", 1));
	data->win.img = mlx_new_image(data->libx.mlx, data->win.width,
			data->win.height);
	if (!data->win.img)
		clean_exit(data, "When creating a new image\n", 1);
	data->win.addr = (int *)mlx_get_data_addr(data->win.img, &data->win.bpp,
			&data->win.sz, data->win.endian);
	mlx_do_key_autorepeatoff(data->libx.mlx);
}