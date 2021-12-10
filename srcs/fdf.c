/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:55:32 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/10 17:08:51 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"



int	main(int argc, char **argv)
{
	t_data	data;
	int	i, j;

	i = 0;
	j = 0;

	data_init(&data);
	//args_checker(argc);
	//ext_checker(argv[1]);
	data.map = NULL;
	map_parser(argv[1], &data);
	camera_init(&data);
	return (0);
}