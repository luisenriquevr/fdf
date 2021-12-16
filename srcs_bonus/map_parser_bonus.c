/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:02:08 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/16 12:43:51 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	array_length(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
		i++;
	return (i);
}

static int	double_free(t_data *data)
{
	int	i;

	i = data->ncols - 1;
	if (!data->read.buf)
		return (-1);
	while (i >= 0)
	{
		free(data->read.buf[i]);
		data->read.buf[i] = NULL;
		i--;
	}
	free(data->read.buf);
	data->read.buf = NULL;
	return (0);
}

static void	get_wh(char *filename, t_data *data)
{
	int		fd;

	data->nrows = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		clean_exit(data, "Fdf file could not be opened\n", 1);
	while (get_next_line(fd, &data->line, &data->read.b, &data->read.l))
	{
		ft_split(data->line, ' ', data);
		data->ncols = array_length(data->read.buf);
		data->nrows++;
		double_free(data);
		free(data->line);
		data->line = NULL;
	}
	free(data->line);
	data->line = NULL;
	close(fd);
	if (data->nrows == 0 || data->ncols == 0)
		clean_exit(data, "There is no map or it has only one line.\n", 1);
}

static void	fill(char *line, int *map_line, t_data *data)
{
	int		i;

	i = 0;
	ft_split(line, ' ', data);
	while (data->read.buf[i])
	{
		map_line[i] = ft_atoi(data->read.buf[i]);
		i++;
	}
	double_free(data);
}

void	map_parser(char *filename, t_data *map)
{
	int		i;
	int		fd;

	i = 0;
	get_wh(filename, map);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		clean_exit(map, "Fdf file could not be opened\n", 1);
	map->map = (int **)malloc(sizeof(int *) * map->nrows);
	while (i < map->nrows)
		map->map[i++] = (int *)malloc(sizeof(int) * map->ncols);
	i = 0;
	while (get_next_line(fd, &map->line, &map->read.b, &map->read.l))
	{
		fill(map->line, map->map[i++], map);
		free(map->line);
		map->line = NULL;
	}
	close(fd);
}
