/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:37:56 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/01 11:05:25 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fill_matrix(int *z_line, char *line)
{
	char	**values;
	int	i;

	values = ft_split(line, ' ');
	i = 0;
	while (values[i])
	{
		z_line[i] = ft_atoi(values[i]);
		free(values[i]);
		i++;
	}
	free(values);
}

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	n_words;

	i = 0;
	n_words = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		n_words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n_words);
}

int	get_width(char *file_name)
{
	char	*line;
	int fd;
	int	width;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_count_words(line, ' ');
	free(line);
	return (width);
}

int	get_height(char *file_name)
{
	char	*line;
	int	fd;
	int	height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	map_parser(char *file_name, t_data *data)
{
	int	fd;
	char *line;
	int	i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i++], line);
		free(line);
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
