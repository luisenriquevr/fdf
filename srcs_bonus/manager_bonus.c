/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:31:38 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/16 14:30:03 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int exitt(t_data *data)
{
	clean_exit(data, "Closing program...\n", 0);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == (int)KEY_ESCAPE)
		exitt(data);
	if (key == KEY_W)
		data->cam.y -= 20;
	if (key == KEY_A)
		data->cam.x -= 20;
	if (key == KEY_D)
		data->cam.x += 20;
	if (key == KEY_S)
		data->cam.y += 20;
	perspective(data, key);
	camera_mov(data, key);
	if (key == KEY_W || key == KEY_A || key == KEY_D || key == KEY_S ||
			data->mov)
	{
		data->mov = 0;
		mlx_destroy_image(data->libx.mlx, data->win.img);
		data->win.img = mlx_new_image(data->libx.mlx, data->win.width,
				data->win.height);
		if (!data->win.img)
			clean_exit(data, "When creating a new image\n", 1);
		data->win.addr = (int *)mlx_get_data_addr(data->win.img,
				&data->win.bpp, &data->win.sz, &data->win.endian);
		image_creator(data);
	}
	return (1);
}

void	map_free(t_data *data)
{
	int	i;

	i = data->nrows - 1;
	if (data->map)
	{
		while (i >= 0)
		{
			free(data->map[i]);
			data->map[i] = NULL;
			i--;
		}
		free(data->map);
		data->map = NULL;
	}
}

void	clean_exit(t_data *data, char *str, int error)
{
	int	len;

	len = ft_strlen(str);
	if (error)
		write(1, "Error\n", 6);
	if (!str)
		perror("");
	else
		write(1, str, len);
	if (data != NULL)
	{
		if (data->win.img)
			mlx_destroy_image(data->libx.mlx, data->win.img);
		if (data->libx.window)
			mlx_destroy_window(data->libx.mlx, data->libx.window);
		map_free(data);
		if (data->line)
			free(data->line);
		if (data->read.l)
			free(data->read.l);
		if (data->read.b)
			free(data->read.b);
	}
	exit(1);
}
