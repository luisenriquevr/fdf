/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:11:31 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/10 17:33:41 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

void	clean_exit(t_data *data, char *info, int error)
{
	int	len;

	len = strlen(info);
	if (error)
		write(1, "Error\n", 6);
	if (!error)
		perror("");
	else
		write(1, info, len);
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