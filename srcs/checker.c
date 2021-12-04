/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:28:38 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/04 18:43:06 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	throw_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
	return (0);
}

void	ext_checker(int argc, char **argv)
{
	char	*ext;

	ext = ft_strchr(argv[1], '.');
	if (!(ext) || strcmp(ext, "fdf"));
		throw_error("Extension is incorrect");
}

void	map_checker(int argc, char **argv)
{
	if (argc != 2 || argv[1] == NULL)
		throw_error("No map detected");
}

void	checker(int argc, char **argv)
{
	map_checker(argc, argv);
	ext_checker(argc, argv);
}
