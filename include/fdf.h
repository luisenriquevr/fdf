/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:55:34 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/01 17:58:39 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx_macos/mlx.h"
# include "../libs/get_next_line/get_next_line.h"

typedef struct	s_data
{
	int	width;
	int	height;
	int	**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

int	main(int argc, char **argv);
void	map_parser(char *file_name, t_data *data);
void	bresenham(float x, float y, float x1, float y1, t_data *data);

#endif
