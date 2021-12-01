/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:55:32 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/02 00:29:58 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	deal_key(int key, t_data *data)
{
	printf("%d\n", key);
	
	if (key == 53)
		exit(0);
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	map_parser(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	data->shift_x = 0;
	data->shift_y = 0;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}