/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:41:17 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/16 14:37:05 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	camera_mov(t_data *data, int key)
{
	if (key == KEY_LEFT)
		data->cam.rotate[0] = 1;
	if (key == KEY_RIGHT)
		data->cam.rotate[1] = 1;
	if (key == KEY_UP)
		data->cam.rotate[2] = 1;
	if (key == KEY_DOWN)
	{
		data->cam.rotate[0] = 0;
		data->cam.rotate[1] = 0;
		data->cam.rotate[2] = 0;
		data->cam.angle = 0;
	}
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP)
		data->cam.angle += ANGLE;
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
		data->mov = 1;
}

void	perspective(t_data *data, int key)
{
	if (key == KEY_I)
	{
		data->cam.isometric = ISOMETRIC;
		data->cam.plane = PLANE;
		data->cam.oblique = OBLIQUE;
		data->cam.pangle = PERSPECTIVE_ANGLE;
	}
	if (key == KEY_P)
	{
		data->cam.plane = PLANE1;
		data->cam.isometric = ISOMETRIC0;
		data->cam.oblique = OBLIQUE;
	}
	if (key == KEY_O)
	{
		data->cam.plane = PLANE;
		data->cam.isometric = ISOMETRIC0;
		data->cam.oblique = OBLIQUE1;
		data->cam.pangle = PERSPECTIVE_ANGLE2;
	}
	if (key == KEY_P || key == KEY_O || key == KEY_I)
		data->mov = 1;
}

int	zoom_bonus(int button, int x, int y, t_data *data)
{
	x++;
	y++;
	if (button == M_SCR_U && data->cam.zoom)
		data->cam.zoom += 1;
	if (button == M_SCR_D && data->cam.zoom)
		data->cam.zoom -= 1;
	if (!data->cam.zoom)
		data->cam.zoom = 1;
	if ((button == M_SCR_U || button == M_SCR_D) && data->cam.zoom)
	{
		mlx_destroy_image(data->libx.mlx, data->win.img);
		data->win.img = mlx_new_image(data->libx.mlx, data->win.width,
				data->win.height);
		if (!data->win.img)
			clean_exit(data, "When creating a new image\n", 1);
		data->win.addr = (int *)mlx_get_data_addr(data->win.img, &data->win.bpp,
				&data->win.sz, &data->win.endian);
		image_creator(data);
	}
	return (0);
}

static void	rotate_aux(int *a, int *b, double angle, int plane)
{
	int	pre_a;
	int	pre_b;

	pre_a = *a;
	pre_b = *b;
	if (plane == ROT_Z)
	{
		*a = pre_a * cos(angle) - pre_b * sin(angle);
		*b = -pre_a * sin(angle) + pre_b * cos(angle);
	}
	else
	{
		*a = pre_a * cos(angle) + pre_b * sin(angle);
		*b = pre_a * sin(angle) + pre_b * cos(angle);
	}
}

void	rotate(int *x, int *y, int *z, t_data *data)
{
	if (data->cam.rotate[0])
		rotate_aux(y, z, data->cam.angle, ROT_X);
	if (data->cam.rotate[1])
		rotate_aux(x, z, data->cam.angle, ROT_Y);
	if (data->cam.rotate[2])
		rotate_aux(x, y, data->cam.angle, ROT_Z);
}
