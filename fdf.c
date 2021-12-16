/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:55:32 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/16 14:52:12 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

void	ext_checker(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 4], ".fdf", 4) != 0)
		clean_exit(NULL, "The file extension must be .fdf\n", 1);
}

void	argc_checker(t_data *data, int argc)
{
	if (argc != 2)
		clean_exit(data, "Invalid number of arguments\n", 1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data_init(&data);
	argc_checker(&data, argc);
	ext_checker(argv[1]);
	map_parser(argv[1], &data);
	camera_init(&data);
	mlx_func_init(&data);
	mlx_hook(data.libx.window, 2, 1, key_press, &data);
	mlx_hook(data.libx.window, 17, (1U << 17), exitt, &data);
	image_creator(&data);
	mlx_loop(data.libx.mlx);
	return (0);
}